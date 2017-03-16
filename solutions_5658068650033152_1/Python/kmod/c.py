import sys

def cando(n, m, k, s):
    assert n <= m
    assert n >= 1
    assert m >= 1
    assert k <= n * m
    if s <= 0:
        return False
    if s >= k:
        # print "can do", n, m, k, s
        return True
    if n >= 3 and m >= 3 and s >= 4:
        submin = findmin(n-2, m-2, k-s)
        if s >= submin + 4 or submin == 1 and s >= 4:
            # print "can do", n, m, k, s
            return True

    # assert n in (1, 2)
    assert s < k
    return False

mins = {}
def findmin(n, m, k):
    if k > n * m:
        return 10000000
    assert n <= m

    p = (n, m, k)
    if p in mins:
        return mins[p]

    for s in xrange(1, k+1):
        if cando(n, m, k, s):
            # print "findmin(%d, %d, %d) = %d" % (n, m, k, s)
            mins[p] = s
            return s
    assert 0

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, M, K = map(int, f.readline().split())

        if N > M:
            N, M = M, N

        r = findmin(N, M, K)
        print "Case #%d: %d" % (_T+1, r)
