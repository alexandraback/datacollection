T = int(input())
for test in range(T):
  n,m = map(int,input().split())
  d=[]
  for i in range(n):
    d.append(list(map(int,input().split())))
  N = []
  for i in range(n):
    N.append(d[i][0])
    for j in d[i]:
      N[i]=max(j,N[i])
  M =[]
  for j in range(m):
    M.append(d[0][j])
    for i in range(n):
      M[j]=max(M[j],d[i][j])

  ver = "YES"
  for i in range(n):
    for j in range(m):
      if d[i][j]<N[i] and d[i][j]<M[j]:
        ver = "NO"
  print("Case #",test+1,": ",ver,sep='')

