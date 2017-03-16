import collections
import sys

Q = collections.namedtuple("Q", "sign val")
def qmul(q1, q2):
    sign = q1.sign * q2.sign
    if q1.val == '1':
        return Q(sign, q2.val)
    if q2.val == '1':
        return Q(sign, q1.val)
    if q1.val == q2.val:
        return Q(-sign, '1')
    if q1.val == 'i' and q2.val == 'j':
        return Q(sign, 'k')
    if q1.val == 'i' and q2.val == 'k':
        return Q(-sign, 'j')
    if q1.val == 'j' and q2.val == 'i':
        return Q(-sign, 'k')
    if q1.val == 'j' and q2.val == 'k':
        return Q(sign, 'i')
    if q1.val == 'k' and q2.val == 'i':
        return Q(sign, 'j')
    if q1.val == 'k' and q2.val == 'j':
        return Q(-sign, 'i')
    assert 0, (q1, q2)

def qpow(q, n):
    r = Q(1, '1')
    t = q
    while n:
        if n & 1:
            r = qmul(r, t)
        t = qmul(t, t)
        n = n >> 1
    return r

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        L, X = map(int, f.readline().split())
        assert X > 0
        assert L > 0
        s = f.readline().strip()
        assert len(s) == L

        q = Q(1, '1')
        for c in s:
            q = qmul(q, Q(1, c))
        q = qpow(q, X)
        if q != qmul(Q(1, 'i'), qmul(Q(1, 'j'), Q(1, 'k'))):
            print "Case #%d: NO" % (_T + 1,)
            continue

        q = Q(1, '1')
        I = Q(1, 'i')
        for i in xrange(L * 4):
            q = qmul(q, Q(1, s[i % L]))
            if q == I:
                break
        else:
            assert q == Q(1, '1')
            print "Case #%d: NO" % (_T + 1,)
            continue

        q = Q(1, '1')
        K = Q(1, 'k')
        for k in xrange(L * X - 1, L * (X - 4) - 1, -1):
            q = qmul(Q(1, s[k % L]), q)
            if q == K:
                break
        else:
            assert q == Q(1, '1')
            print "Case #%d: NO" % (_T + 1,)
            continue

        if k > i + 1:
            print "Case #%d: YES" % (_T + 1,)
        else:
            print "Case #%d: NO" % (_T + 1,)
