import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next


def solve(s):
    memo = [""]
    for fulllen in xrange(1,len(s)+1):
        out = chr(ord('A')-1)
        sout = chr(ord('A')-1)
        for idx in xrange(fulllen):
            ss = s[idx] + memo[idx] + s[idx+1:fulllen]
            if ss > out:
                out = ss
        if out == sout: 
            out = ''
        memo.append(out)
    return memo[-1]

T = int(cin())
for cn in xrange(1,T+1):
    s = cin()
    print "Case #%d: %s" % (cn, solve(s))


