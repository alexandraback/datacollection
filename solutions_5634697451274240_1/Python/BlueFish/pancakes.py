def solve(s): s=s+'+'; return [s[i]!=s[i+1] for i in range(len(s)-1)].count(True)

inp=file('B-large.in','rb+'); out=file('B-large.out','wb+')

T=int(inp.readline().strip())

for i in range(1,T+1): out.write('Case #%i: %i\r\n'%(i,solve(inp.readline().strip())))