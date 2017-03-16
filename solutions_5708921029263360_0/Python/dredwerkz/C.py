import sys
import time

SINGLELINE = 1


def solve():
    a, b, c, m = [int(a) for a in raw_input().split(" ")]

    arr = []
    cnta = {}
    cntb = {}
    cntc = {}
    for i in xrange(1, a+1):
        for j in xrange(1, b+1):
            for k in xrange(1, c+1):
                ka = i*100+j
                kb = k*100+j
                kc = i*100+k
                cnta[ka] = cnta.get(ka, 0)
                cntb[kb] = cntb.get(kb, 0)
                cntc[kc] = cntc.get(kc, 0)

                if cnta[ka] == m or cntb[kb] == m or cntc[kc] == m:
                    continue

                cnta[ka] += 1
                cntb[kb] += 1
                cntc[kc] += 1

                arr.append((i,j,k))

    print len(arr)
    for a, b, c in arr:
        print "%d %d %d" % (a, b, c)








########################################################################
_TOKENS = []
_TOKENS_POS = 0
def gs():
    global _TOKENS, _TOKENS_POS
    while _TOKENS_POS == len(_TOKENS):
        _TOKENS = raw_input().split(" ")
        _TOKENS_POS = 0
        while _TOKENS_POS < len(_TOKENS) and _TOKENS[_TOKENS_POS] == "":
            _TOKENS_POS += 1
    _TOKENS_POS += 1
    return _TOKENS[_TOKENS_POS-1]
def gi():
    return int(gs())
def pr(a, newline=True):
    if not isinstance(a, basestring):
        a = str(a)
    if newline:
        a += "\n"
    sys.stdout.write(a)
    sys.stdout.flush()
if __name__ == '__main__':
    starttime = time.time()
    t = gi()
    for i in xrange(t):
        casetime = time.time()
        pr("Case #%d:%s" % (i+1, " " if SINGLELINE else "\n"), False)
        solve()
        currtime = time.time()
        casetime = currtime - casetime
        sys.stderr.write("Case %d took %s time. Estimated time remaining: %s\n" % (i+1, casetime, (currtime - starttime) * t / (i+1)))
