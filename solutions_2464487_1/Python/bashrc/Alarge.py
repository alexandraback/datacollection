global r
global t
r=0
t=0

def fun(n):
  m=int(n)
  ans=0
  ans=2*m*r
  ans+=2*m*m
  ans-=1
  return ans
def search():
  
  high,low=(10**18,0)
  mid=0
  while low<high:
    mid=(high+low)/2
    if fun(mid)<=t and fun(mid+1)>t:
      return mid
    elif fun(mid)>t:
      high=mid
    elif fun(mid)<t:
      low=mid+1
      
    
test=input()
for i in range(0,test):
  print "Case #"+str(i+1)+":",
  r,t=raw_input().split(' ')
  r=int(r)
  t=int(t)
  print search()
