def loz(S):
    return S == "+"

def case(S):
    r = 0
    last = S[0]
    for i in xrange(1, len(S)):
        new = S[i]
        if last != new:
            r += 1
        last = new
    begin = S[0]
    r += ((loz(S[0]) + r + 1) % 2)
    return r

if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(1, T + 1):
        S = raw_input().strip()
        print "Case #%d: %s" % (i, case(S))
