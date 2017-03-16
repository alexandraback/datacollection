g=open("jamcoins_large.out","w")

N = 2**14
L = []

for k in range(0,N):
  mid = ""
  for j in range(0,14):
    aux = (k/2**j)%2
    mid = str(mid)+str(aux)
  L.append(mid) 

divisors = ""
for k in range(2,11):
  divisors = divisors + str(k**16+1) + " "  
divisors = divisors[:-1]

coins = []
for k in range(0,N):
  coin = "1"+L[k]+"1"
  coin = coin+coin
  coins.append(coin)

g.write("Case #"+str(1)+":"+"\n")
for j in range(0,500):
  g.write(coins[j]+" "+divisors+"\n")
  
    

  
  
  
