def dfs(i):
  if i == len(l): return 0
  res=dfs(i+1)
  a,b=l[i]
  if fst[a]>1 and snd[b] > 1:
    fst[a]-=1
    snd[b]-=1
    res=max(res, 1+dfs(i+1))
    fst[a]+=1
    snd[b]+=1
  return res

for t in range(int(raw_input())):
  n=int(raw_input())
  l=[]
  fst={}
  snd={}
  for i in range(n):
    s=raw_input()
    a,b=s.split()
    l.append((a,b))
    fst[a] = fst.get(a,0)+1
    snd[b] = snd.get(b,0)+1
  res=dfs(0)
  print "Case #{}: {}".format(t+1, res)


