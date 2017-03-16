f=open("D-large.in","r")
g=open("tiles.out","w")

def baseconv(L,k):
  num = 0 
  N = len(L) 
  for j in range(0,N):
    num += L[j]*(k**j)
  return num

T = int(f.readline())

for i in range(0,T):
  [K,C,S] = map(int,f.readline().split())
  stud = []
  
  for j in range(0,S):
    ind = []
    for k in range(0,C):
      ind.append((C*j+k)%K)
    stud.append(ind)
  
  positions = [baseconv(x,K)+1 for x in stud]
  finalpos = []
  
  for j in range(0,S):
    if positions[j] not in positions[:j]:
      finalpos.append(positions[j])
  
  h = 1
  while len(finalpos) < S:
    if h not in finalpos:
      finalpos.append(h)
    h+=1    
  
  finalpos_str = ""
  for x in finalpos:
    finalpos_str = finalpos_str + str(x) + " "
  finalpos_str = finalpos_str[:-1]

  if S*C>=K:
    ans = finalpos_str
  else:
    ans = "IMPOSSIBLE"
  
  g.write("Case #"+str(i+1)+": "+ans+"\n")

  
  
  
