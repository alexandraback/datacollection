def solve(n):
 if n==0: return 'INSOMNIA'
 else:
  m=n; seen=set(str(m))
  while len(seen)<10: m+=n; seen=seen|set(str(m))
  return m

inp=file('A-large.in','rb+'); out=file('A-large.out','wb+')

T=int(inp.readline().strip())

for i in range(1,T+1):
 out.write('Case #%i: %s\r\n'%(i,solve(int(inp.readline().strip()))))