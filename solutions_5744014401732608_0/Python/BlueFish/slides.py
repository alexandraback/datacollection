def solve(B,M):
 if M>(2**(B-2)): return False
 else:
  slides=[]
  for end in range(1,B-1):
   for start in range(end): slides.append((start,end))
  for b in range(B-2,0,-1):
   if M>=(2**(b-1)): M-=(2**(b-1)); slides.append((b,B-1))
  if M>=1: M-=1; slides.append((0,B-1))
  out=[[0]*B for i in range(B)]
  for i,j in slides: out[i][j]=1
  return '\r\n'.join([''.join([str(n) for n in line]) for line in out])

inp=file('B-small-attempt0.in','rb+'); out=file('B-small-attempt0.out','wb+')

T=int(inp.readline().strip())

for i in range(1,T+1):
 B,M=[int(s) for s in inp.readline().strip().split(' ')]
 sol=solve(B,M)
 outline='Case #%i: %s'%(i,('POSSIBLE' if sol else 'IMPOSSIBLE'))
 if sol: outline=outline+'\r\n'+sol
 print outline
 out.write(outline+'\r\n')