f=open("A.in","r")
g=open("target.out","w")
import math
T = int(f.readline())

for i in range(0,T):
  X = f.readline().split( )
  r = int(X[0])
  t = int(X[1])
  
  for k in range(0,t+1):
    if t-k*(2*(r+k)-1)<0:
      ans = k-1
      break

  g.write("Case #"+str(i+1)+": "+str(ans)+"\n")
