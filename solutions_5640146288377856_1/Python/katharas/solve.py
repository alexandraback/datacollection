
def solve_line(C, W):
    if W==1:
        return C

    return C//W

def solve(R,C,W):
    if C%W == 0:
        return R*solve_line(C, W) + W-1
    else:
        return R*solve_line(C, W) + W

T = int(raw_input())
for t in xrange(1, T+1):
    R,C,W = map(int, raw_input().split())
    print "Case #%d: %d" % (t, solve(R,C,W))
