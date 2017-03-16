
import sys

T = int(sys.stdin.readline())

def d(R, C, W):
    if W == 1:
        return C
    if W == C:
        return W
    if W > C//2:
        return W+1

    return 1 + d(1, C-W, W)

for i in range(1, T+1):
    R, C, W = map(int, sys.stdin.readline().strip().split(" "))

    print "Case #%s: %s" % (i, d(R, C, W))
