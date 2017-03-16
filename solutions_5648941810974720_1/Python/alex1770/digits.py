import sys

def thing(S):
  d=[[0,"ZERO","Z"],
     [6,"SIX","X"],
     [8,"EIGHT","G"],
     [2,"TWO","W"],
     [7,"SEVEN","S"],
     [5,"FIVE","V"],
     [3,"THREE","H"],
     [4,"FOUR","R"],
     [1,"ONE","O"],
     [9,"NINE","I"]]
  ans=[None]*10
  e={}
  for x in S: e[x]=e.get(x,0)+1
  for (a,b,c) in d:
    n=e.get(c,0)
    ans[a]=n
    for x in b: e[x]=e.get(x,0)-n
  for x in e: assert e[x]==0
  r=""
  for i in range(10): r+=str(i)*ans[i]
  return r

T=int(sys.stdin.readline())
for case in range(1,T+1):
  S=sys.stdin.readline().strip()
  print "Case #%d:"%case,thing(S)
