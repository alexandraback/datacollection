import sys

def solve(A, B, K):
    c = 0
    for a in range(A):
        for b in range(B):
            if (a & b) < K:
                c += 1
    return c

f = open(sys.argv[1])
T = int(f.readline())
for t in xrange(1,T+1):
    a, b, k = map(int, f.readline().strip().split())
    print "Case #{0}: {1}".format(t, solve(a, b, k))
