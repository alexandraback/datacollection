import sys

T = int(sys.stdin.readline())

for testNum in range(T):

    A, B, K = map(int, sys.stdin.readline().strip().split())

    tally = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                tally += 1

    ans = str(tally)

    print "Case #%d: %s"%(testNum+1, ans)
