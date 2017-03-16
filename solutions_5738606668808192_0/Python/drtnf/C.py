import sys

input = sys.stdin

def makeBitSet(n,l):
  bs = [1]
  ll=0
  while ll<l:
    if n%2==1:
      bs.append(1)
    else:
      bs.append(0)
    n= n//2
    ll+=1
  bs.append(1)  
  bs.reverse()
  return bs  

def getNum(bs, j):
  jj, acc = 1, 0
  for x in bs[::-1]:
    acc+=x*jj
    jj*=j
  return acc 

#naive
def getDiv(x):
  i = 2
  while i**2<=x:
    if x%i==0:
      return i
    i+=1
  return -1  


def jamCoins(N, J):
  mx = 2**(N-2)
  jamCoins = []
  for i in range(mx):
#    print(i)
    flag, j, bs =True, 2,  makeBitSet(i, N-2)
#    print(bs)
    div = []
    while flag:
      x = getDiv(getNum(bs, j))
      if x == -1:
        flag=False
      else:
        div.append(x)
        j+=1
      if j==11:
        jamCoins.append((bs, div))
        flag = False
    if len(jamCoins)==J:
      return jamCoins
  return jamCoins  
  

for case in range(int(input.readline())):
      values = input.readline().split()
      print("Case #"+ str(case+1) +":")
      jC = jamCoins(int(values[0]),int(values[1]))
      for j in jC:
        ans = ''
        for x in j[0]:
          if x==1:
            ans +='1'
          else:
            ans +='0'
        for x in j[1]:
          ans += ' '+ str(x)
        print(ans)
        
        
  
