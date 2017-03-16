import sys, math

infile = sys.stdin

def solve(A, B):
    ret = 0
    i = 0
    j = 0
    n = len(A)
    assert len(A) == len(B)
    while i < n and j < n:
        assert(A[i] != B[j])
        if A[i] > B[j]:
            i += 1
            j += 1
            ret += 1
        else:
            i += 1
    return ret

T = int(infile.readline())

for case_num in xrange(1, T+1):
    N = int(infile.readline())
    A = sorted([float(v) for v in infile.readline().split()])
    B = sorted([float(v) for v in infile.readline().split()])
    # print A
    # print B
    print "Case #%d: %d %d" % (case_num,
                               solve(A, B),
                               N - solve(B, A))
