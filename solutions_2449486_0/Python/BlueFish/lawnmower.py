input = file('B-small-attempt0.in','rb+'); output=file('B-small-attempt0.out','wb+')
ncases = int(input.readline().strip())

for k in range(ncases):
 N,M = [int(x) for x in input.readline().strip().split()]
 lawn = [[int(x) for x in input.readline().strip().split()] for line in range(N)]
 doable = True
 for i in range(N):
  for j in range(M):
   doablelong  = (map(lambda x: x<=lawn[i][j], [lawn[h][j] for h in range(N)]) == [True]*N)
   doabletrans = (map(lambda x: x<=lawn[i][j], [lawn[i][h] for h in range(M)]) == [True]*M)
   if not(doablelong or doabletrans): doable = False; break
  if not(doable): break
 output.write('Case #'+str(k+1)+': '+['NO','YES'][doable]+'\n')