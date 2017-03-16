def preveri():
  for i in range(len(b)):
    if b[i]!=[False,False]:
      return False
  return True

for l in range(int(raw_input())):
  t=[]
  for j in range(int(raw_input())):
    t.append([int(k) for k in raw_input().split()])
  b=[[True, True] for i in range(len(t))]
  st=n=0
  g=True
  while g==True:
    g=False
    c=True
    while c==True:
      c=False
      for i in range(len(t)):
	if t[i][1]<=st and b[i][1]==True:
	  if b[i][0]==True:
	    st+=2
	  else:
	    st+=1
	  b[i][1]=False
	  b[i][0]=False
	  g=True
	  c=True          
	  n+=1
    c=False
    a=[]
    for i in range(len(t)):
      if t[i][0]<=st and b[i][0]==True and (len(a)==0 or a[1]<t[i][1]):
	a=[i,t[i][1]]
    if len(a)>0:
      c=True
      st+=1
      b[a[0]][0]=False
      n+=1
      g=True
	#st+=1
	#b[i][0]=False
	#n+=1
	#c=True
	#g=True
	#break
    if c==False and preveri()==False:
      n='Too Bad'
  print "Case #%d: %s" %(l+1, str(n))      
 