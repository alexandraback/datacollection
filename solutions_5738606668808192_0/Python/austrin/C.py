import random
import sys

inp = sys.stdin
outp = sys.stdout

def div(N):
    r = 3
    while r*r <= N and r <= 500:
        if N % r == 0: return r
        r += 2
    return None

def ok(S):
    ret = []
    for B in range(2, 11):
        N = 0
        for b in S:
            N = B*N + b
        d = div(N)
        if d is None: return None
        ret.append(d)
    return ret
    
def solve():
    (N,J) = map(int, inp.read().split())
    print ''
    seen = set()
    while J > 0:
        while True:
            S = [1] + [random.randint(0,1) for _ in range(N-2)] + [1]
            Sv = ''.join(map(str, S))
            if Sv not in seen:
                break
        seen.add(Sv)
        divs = ok(S)
        if divs is None:
            continue
        print '%s %s' % (Sv, ' '.join(map(str, divs)))
        J -= 1












T = int(inp.readline())
for i in range(T):
    outp.write('Case #%d: ' % (i+1))
    solve()
