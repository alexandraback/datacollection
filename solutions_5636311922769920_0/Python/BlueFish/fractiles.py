inp=file('D-small-attempt0.in','rb+'); out=file('D-small-attempt0.out','wb+')

T=int(inp.readline().strip())

def solve(K,C,S):
 if S*C<K: return 'IMPOSSIBLE'
 else:
  out=[]; f=range(K)
  while f: m=f[:C]; f=f[C:]; out.append(sum([m[i]*(K**i) for i in range(len(m))])+1)
  return ' '.join([str(x) for x in out])

for i in range(1,T+1):
 K,C,S=[int(x.strip()) for x in inp.readline().strip().split(' ')]
 print 'Case #%i: %s'%(i,solve(K,C,S))
 out.write('Case #%i: %s\r\n'%(i,solve(K,C,S)))