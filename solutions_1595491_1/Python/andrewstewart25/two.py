import sys 
def solve(n,p):
  a=n/3
  b=[a,a,a]
  d=[a,a,a]
  c = n-a*3
  if c==1:
    b[0]+=1
    d[0]+=1
  elif c==2:
    b[0]+=1
    b[1]+=1
    if (d[0]<9):d[0]+=2
    else:
      d[0]+=1
      d[1]+=1
  elif c==0:
    if 0<d[0]<10:
      d[0]+=1
      d[2]-=1


  x,y=0,0
  if b[0]>=p:
    x=1 
  if d[0]>=p:
    y=1 
  return x,y 

def count(s,p,*t):
  n,S=0,0
  for x in t:
    a=solve(x,p)
    n+=a[0]
    S+=a[1]

  N = n + min(S-n,s)
  return N

data = sys.stdin.readlines()
c=1
for line in data[1:]:
  line = map(int,line.strip().split(" "))
  n = line[0]
  s = line[1]
  p = line[2]
  t = line[3:]
  print "Case #%s: %s"%(c,count(s,p,*t))
  c+=1
