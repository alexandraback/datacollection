import sys

def val(l):
  ld={};rd={}
  v=0
  for (x,y) in l:
    if x in ld and y in rd: v+=1
    ld[x]=1;rd[y]=1
  return v
    
def thing(N,l):
  m=[]
  for x in l:
    bv=-1
    for i in range(len(m)+1):
      m1=m[:i]+[x]+m[i:]
      v=val(m1)
      if v>bv: bv=v;bm=m1
    m=bm
  return bv

T=int(sys.stdin.readline())
for case in range(1,T+1):
  N=int(sys.stdin.readline().strip())
  l=[]
  for i in range(N):
    l.append(sys.stdin.readline().strip().split())
  print "Case #%d:"%case,thing(N,l)
