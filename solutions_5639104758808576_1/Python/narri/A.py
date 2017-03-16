import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next

def solve(s):
    have = 0
    out = 0
    for i in xrange(len(s)):
        z = ord(s[i])-ord('0')
        if have < i:
            out += i - have
            have = i
        have += z
    return out

T = int(cin())
for cn in xrange(1,T+1):
    _, s = cin(), cin()
    print "Case #%d: %d" % (cn, solve(s))


