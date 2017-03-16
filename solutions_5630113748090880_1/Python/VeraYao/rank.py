f = open('B-large.in','r') 
T = int(f.readline()) 
for k in range(T): 
  N = int(f.readline())
  q = [] 
  for i in range(2*N-1):
    st = f.readline().split() 
    for j in range(N):
      temp = int(st[j])
      if temp in q: q.remove(temp) 
      else: q.append(temp)
  ans = sorted(q) 
  print 'Case #'+str(k+1)+': ',
  for i in range(N):
    print ans[i], 
  print
