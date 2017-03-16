import sys

inp = sys.stdin
outp = sys.stdout
    
def solve():
    (K, C, S) = map(int, inp.readline().split())
    if S*C < K:
        print ' IMPOSSIBLE'
        return

    at = 0
    seen = set()
    for i in range(S):
        out = 0
        for i in range(C):
            out += at * K ** (C-i-1)
            at = (at+1) % K
        assert out < K**C
        if out in seen: continue
        seen.add(out)
        outp.write(' %s' % (out+1))
    print







T = int(inp.readline())
for i in range(T):
    outp.write('Case #%d:' % (i+1))
    solve()
