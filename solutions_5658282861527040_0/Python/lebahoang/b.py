import sys
def solve(A,B,K):
    sum = 0
    for i in xrange(A):
        for j in xrange(B):
            c = i&j
            if c < K:
                sum += 1
    return sum
T = int(sys.stdin.readline())
case = 1
for _ in xrange(T):
    A,B,K = map(int,sys.stdin.readline().strip().split())
    print "Case #%d: %d" %(case, solve(A,B,K))
    case += 1
