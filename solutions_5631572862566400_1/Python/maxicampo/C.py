f=open("C-large.in","r")
g=open("friends.out","w")

def doublebonds(K):
  bonds = []
  for j in range(0,len(K)):
    if K[K[j]] == j and [K[j],j] not in bonds:
      bonds.append([j,K[j]])
  return bonds

def occur(L,m):
  ans = []
  while m in L:
    j = L.index(m)
    if len(ans) == 0:
      ans.append(j)
    else:
      ans.append(j+1+ans[-1])
    L = L[j+1:]
  return ans

def longestpath(L,x):
  occ = occur(L,x)
  if occ == []:
    return 0
  else:
    ans = max([longestpath(L,y) for y in occ])+1
    return ans

def applyfunc(K,L):
  ans = [K[x] for x in L]
  return ans
      
def longestcycle(K):
  n = len(K)
  H = [K]
  for j in range(0,n):
    H.append(applyfunc(K,H[-1]))
  cycles = []

  for j in range(0,n):
    for i in range(0,n):
      if H[i][j] == j:
        cycles.append(i+1)
        break
    else:
      cycles.append(0)
  ans = max(cycles)
  return ans

  
  
  
  
T = int(f.readline())

for i in range(0,T):
  N = int(f.readline())
  K = [x-1 for x in map(int,f.readline().split())]
  bonds = doublebonds(K)
  ans = 0
  for pair in bonds:
    x = pair[0]
    y = pair[1]
    listx = K[:y]+[-1]+K[y+1:] 
    listy = K[:x]+[-1]+K[x+1:]
    aux = longestpath(listx,x) + longestpath(listy,y) + 2
    ans = ans + aux

  
    
  cycle = longestcycle(K)
  ans = max(ans,cycle)

  g.write("Case #"+str(i+1)+": "+str(ans)+"\n")

  
  
  
