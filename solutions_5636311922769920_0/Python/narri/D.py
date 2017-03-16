import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next

def basis(aa, base):
    out = 0
    for t in aa:
        out *= base
        out += t
    return out

def solve(K, C, S):
    if S*C < K:
        return "IMPOSSIBLE"
    x = 0 
    arr = []
    out = []
    while x < K:
        arr.append(x)
        x += 1
        if len(arr) == C:
            out.append(basis(arr, K))
            arr = []
    if arr:
        out.append(basis(arr,K))
    return ' '.join(str(t+1) for t in out)


T = int(cin())
for cn in xrange(1,T+1):
    k, c, s = int(cin()), int(cin()), int(cin())
    print "Case #%d: %s" % (cn, str(solve(k,c,s)))


