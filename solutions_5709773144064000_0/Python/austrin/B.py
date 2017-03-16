import sys

inp = sys.stdin
outp = sys.stdout
    
def solve():
    (C,F,X) = map(float, inp.readline().split())
    r = X/2
    f = 0
    s = 0
    while s < r:
        s += C/(2+F*f)
        f += 1
        r = min(r, s + X/(2+F*f))
    print r












T = int(inp.readline())
for i in range(T):
    outp.write('Case #%d: ' % (i+1))
    solve()
