import sys

def solve(A, B, K):
    count = 0
    for i in xrange(A):
        for j in xrange(B):
            if i & j < K:
                count += 1
    return count


if __name__ == '__main__':
    f = sys.stdin
    T = int(f.readline())
    for i in xrange(1, T+1):
        A, B, K = map(int, f.readline().split())
        print "Case #%d: %d"  % (i, solve(A, B, K))
