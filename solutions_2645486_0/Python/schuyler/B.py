

T = int(input())
for t in range(1,T+1):
  ln = input().split()
  E = int(ln[0])
  R = int(ln[1])
  N = int(ln[2])
  ln = input().split()
  v = [int(x) for x in ln]
  
  n = N-1
  maxVals = [e*v[n] for e in range(E+1)]
  #print(n+1, maxVals)
  n -= 1
  while n >= 0:
    newMaxVals = [0 for e in range(E+1)]
    for e in range(R, E+1):
      # max_i (i*v_i + maxVals(e-i+R))
      mx = 0
      for i in range(max(0,e+R-E), 1+e):
        #print(E, R, n, e, i)
        mx = max(mx, i*v[n] + maxVals[e-i+R])
      newMaxVals[e] = mx
    maxVals = newMaxVals
    #print(n+1, maxVals)
    n -= 1
  
  print('Case #' + str(t) + ': ' + str(maxVals[E]))
