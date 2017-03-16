f=open("A-small.in","r")
g=open("whiteboard.out","w")


characters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 'Q','R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'] 

T = int(f.readline())

def occ(L,m):
  ans = []
  while m in L:
    j = L.index(m)
    if len(ans) == 0:
      ans.append(j)
    else:
      ans.append(j+1+ans[-1])
    L = L[j+1:]
  return ans

def quicksorting(L):
  m = L[0]
  occ_all = occ(L,m)
  ans = []
  for j in occ_all:
    ans.append(m)
  for k in range(0,len(L)):
    if L[k] != m:
      ans.append(L[k])
  return ans
      

def sorting(L):
  if len(L) == 0:
    return []
  else:
    m = max(L)
    occ_max = occ(L,m)
    number_max = len(occ_max)
    FIRST = L[:occ_max[0]]
    LAST = L[occ_max[0]:]
    segment1 = sorting(FIRST)
    segment2 = quicksorting(LAST)
    answer = [m for j in range(0,number_max)]+segment1+segment2[number_max:]
    return answer
  


for i in range(0,T):

  N = f.readline()[:-1]
  L = [characters.index(x) for x in N]
  numberans = sorting(L)
  listans = [characters[x] for x in numberans]
  ans = ""
  for j in range(0,len(L)):
    ans += listans[j]
  

  g.write("Case #"+str(i+1)+": "+ans+"\n")

  
  
  
