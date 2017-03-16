f=open("D-small.in","r")
g=open("tiles.out","w")

T = int(f.readline())

for i in range(0,T):
  [K,C,S] = map(int,f.readline().split())
  ans = ""
  for j in range(0,K-1):
    ans = ans+str(j+1)+" "
  ans = ans + str(K)
  g.write("Case #"+str(i+1)+": "+ans+"\n")

  
  
  
