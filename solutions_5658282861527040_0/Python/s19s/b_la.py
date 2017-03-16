T = raw_input()
for t in range(int(T)):
  A, B, K = map(int, raw_input().split())
  C = 0
  for i in range(A):
    for j in range(B):
      if i & j < K: 
        C += 1
  

   
  

  print 'Case #%d: %s' % (t+1, str(C))


  
  