
def solve(R,C,W):
    if R>1:
        return 0

    if W==1:
        return C

    if C%W == 0:
        return C//W + W-1
    else:
        return C//W + W

T = int(raw_input())
for t in xrange(1, T+1):
    R,C,W = map(int, raw_input().split())
    print "Case #%d: %d" % (t, solve(R,C,W))
