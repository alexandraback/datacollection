def solve(s): s=s+'+'; return [s[i]!=s[i+1] for i in range(len(s)-1)].count(True)

inp=file('B-small-attempt0.in','rb+'); out=file('B-small-attempt0.out','wb+')

T=int(inp.readline().strip())

for i in range(1,T+1): out.write('Case #%i: %i\r\n'%(i,solve(inp.readline().strip())))