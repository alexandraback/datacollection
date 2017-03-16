f = open('C-small-attempt0.in','r') 
T = int(f.readline()) 
for k in range(T): 
  N = int(f.readline()) 
  st = f.readline().split() 
  bff = [int(numeric_string) for numeric_string in st] 
  maxbff = 0  
  for i in range(N): 
    q = []
    q.append(i)
    while bff[q[-1]]-1 not in q:
      q.append(bff[q[-1]]-1)
    if bff[q[-1]]-1== i or (len(q)>1 and bff[q[-1]]-1 == q[-2]):
      maxbff = max(maxbff, len(q)) 
    if len(q)>1 and bff[q[-1]]-1 == q[-2]: 
      flag = 0  
      for i in range(N):
        if(bff[i]-1 == q[0] or bff[i]-1 == q[-1]) and i not in q:
          flag = 1
      maxbff = max(maxbff, len(q)+flag)
  print 'Case #'+str(k+1)+': '+str(maxbff)  

