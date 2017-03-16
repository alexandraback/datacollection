import sys

NN = int(sys.stdin.readline().strip())

for i in xrange(NN):
    L = sys.stdin.readline().strip()
    L = map(int, L.split())
    N, S, p = L[:3]
    L = L[3:]
    assert len(L) == N

    c = 0
    for n in L:
        score = (n+2) // 3
        if score >= p:
            c += 1
        if score == p-1 and n%3 != 1 and n >= 2 and S:
            S -= 1
            c += 1
    print "Case #%d: %d" % (i+1, c)
