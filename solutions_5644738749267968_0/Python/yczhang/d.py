import sys

def read_nums():
    sys.stdin.readline()

    A = map(float, sys.stdin.readline().split())
    B = map(float, sys.stdin.readline().split())

    A.sort()
    B.sort()

    return A, B

def solve1(A, B):
    n = len(A)

    res = 0

    j1 = 0
    for i in xrange(n):
        if A[i] > B[j1]:
            res += 1
            j1 += 1

    return res

def solve2(A, B):
    n = len(A)

    res = 0

    j = 0
    for i in xrange(n):
        while j < n and B[j] < A[i]:
            j += 1

        if j < n:
            j += 1
        else:
            res += 1

    return res

T = int(sys.stdin.readline())

for t in xrange(T):
    A, B = read_nums()

    print 'Case #%d: %d %d' % (t+1, solve1(A, B), solve2(A, B))
