import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next


def solve(data):
    data = sorted(data)
    out = data[-1]
    maxim = out
    for ma in xrange(1,maxim+1):
        q = 0
        for thing in data:
            if thing > ma:
                q += (thing-ma+(ma-1)) // ma
        if q + ma < out:
            out = q + ma

    return out

T = int(cin())
for cn in xrange(1,T+1):
    D = int(cin())
    aa = list(int(cin()) for x in xrange(D))
    print "Case #%d: %d" % (cn, solve(aa))


