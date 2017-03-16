import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next

def solve(n):
    if n == 0:
        return "INSOMNIA"
    se = set(str(i) for i in xrange(0,10))
    at = n
    while se:
        for ch in str(at):
            if ch in se:
                se.remove(ch)
        if not se:
            break
        at += n
    return at

T = int(cin())
for cn in xrange(1,T+1):
    s = cin()
    print "Case #%d: %s" % (cn, str(solve(int(s))))


