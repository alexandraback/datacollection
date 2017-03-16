g=open("jamcoins.out","w")

N = 2**6
L = []

for k in range(0,N):
  mid = ""
  for j in range(0,6):
    aux = (k/2**j)%2
    mid = str(mid)+str(aux)
  L.append(mid) 

divisors = ""
for k in range(2,11):
  divisors = divisors + str(k**8+1) + " "  
divisors = divisors[:-1]

coins = []
for k in range(0,N):
  coin = "1"+L[k]+"1"
  coin = coin+coin
  coins.append(coin)

g.write("Case #"+str(1)+":"+"\n")
for j in range(0,50):
  g.write(coins[j]+" "+divisors+"\n")
  
    

  
  
  
