T = int(raw_input ())

for t in range(T) : 
  x = raw_input().split()
  A,B = int(x[0]), int(x[1])
  x = raw_input().split()
  P = [float(i) for i in x]
  S = [] 
  x = P[0]
  S.append(x)
  for i in range(1,A):
    x = x*P[i]
    S.append(x)
  ans = []
  for i in range(A) : 
    l = A+B-2*i-1
    r = l + B + 1
    x = S[i]*l + (1-S[i])*r
    ans.append(x)
  ans.append(B+2)
  ans.append(A+B+1)
  print "Case #%d: %f" %(t+1, min(ans))
  
