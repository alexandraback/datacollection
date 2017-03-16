t=int(raw_input())
def gcd(a,b):
 if(b==0):
  return a
 return gcd(b,a%b)

def dmin(a,b):
 g=gcd(a,b)
 a/=g
 b/=g
 return [a,b]

for ctr in range(1,t+1):
 print "Case #"+str(ctr)+":",
 inp=raw_input()
 inp=inp.split('/')
 inp[0]=int(inp[0])
 inp[1]=int(inp[1])
 res=0
 pow2=1
 ans=1024
 for i in range(41):
  inp=dmin(inp[0],inp[1])
  if inp[0]*pow2 >= inp[1]:
   inp[0]= inp[0]*pow2 - inp[1]
   inp[1]*=pow2
   ans=min(ans,i)
   
  pow2*=2
 
 if(inp[0]!=0):
  print 'impossible'
  continue
 print ans
 
