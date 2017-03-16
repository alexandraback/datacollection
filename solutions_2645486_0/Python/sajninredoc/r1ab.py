#f = open('test', 'r')
f = open('B-small-attempt0.in', 'r')

T = int(f.readline())

for test in range(1, T+1):
  E, R, N = [int(num) for num in f.readline().split()]
  
  values = [int(num) for num in f.readline().split()]
  
  dp = [[0]*(E+1) for i in xrange(N+1)]
  
  
  for t in range(N):
    # process event t
    for e in range(E+1):
      for ep in range(e+1):
	newe = min(e-ep+R, E)
	dp[t+1][newe] = max(dp[t+1][newe], dp[t][e] + ep*values[t])
  
  best = max(dp[N])
  
  print 'Case #' + str(test) + ': ' + str(best)
