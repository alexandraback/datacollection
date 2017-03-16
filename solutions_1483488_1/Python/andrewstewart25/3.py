import sys 
from math import factorial
data={}
for i in xrange(2000001):
  if i in data:continue
  l = [i] 
  j = str(i)
  copy=[i]
  k = j[1:]+j[0]
  while k!=j:
    r = int(k)
    if k[0] == '0' or r>2000000: 
      k = k[1:]+k[0]
      continue
    k = k[1:]+k[0]
    l.append(r)
    copy.append(r)
  for n in copy:
    data[n] = l 

def choose(n,k):
  if k>n:return 0
  return factorial(n)/(factorial(k)*factorial(n-k))

lines = sys.stdin.readlines()
c=1
for line in lines[1:]:
  a,b=map(int,line.split(' '))
  n=[0]*2000001
  tot=0
  for i in xrange(a,b+1):
    if n[i]:continue
    if len(data[i])<=1:continue
    tot1=0
    for d in data[i]:
      n[d]=1
      if a<=d<=b:
        tot1+=1
    tot+=choose(tot1,2)
  print "Case #%s: %s"%(c,tot)
  c+=1
