f=open("B-small0.in","r")
g=open("lotto.out","w")

T = int(f.readline())

for i in range(0,T):
  [A,B,K] = map(int,f.readline().split())
  print i
  count = 0
  for j in range(0,A):
    for k in range(0,B):
      if j&k < K:
        count += 1
  ans = str(count)  

  g.write("Case #"+str(i+1)+": "+ans+"\n")

  
  
  
