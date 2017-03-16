import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next


def solve_(X, R, C):
    if (R*C) % X != 0:
        return True
    if X > 6:
        return True
    #X <= 6 now
    if not (R >= X or C >= X):
        return True
    if X <= 2:
        return False
    if X == 3:
        if not(R >= 2 and C >=2):
            return True
        return False
    if X == 4:
        if not (R >= 3 and C >= 3):
            return True
        #R >= 2 and C >= 2
        if R >= 4 and C >= 4:
            return False
        return False
    if X == 5:
        if not (R>=3 and C>=3):
            return True
        if R >= 5 and C >= 5:
            return False
        return False
    if X == 6:
        if not (R >= 3 and C >= 3):
            return True
        if R == 3 or C == 3: #+sign
            return True
        if R >= 6 and C >= 6:
            return False
        return False

    return None

T = int(cin())
for cn in xrange(1,T+1):
    X, R, C = list(int(cin()) for x in range(3))
    ans = "RICHARD" if solve_(X,R,C) else "GABRIEL"
    print "Case #%d: %s" % (cn, ans)


