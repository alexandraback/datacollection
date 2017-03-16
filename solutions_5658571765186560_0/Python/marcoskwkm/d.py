def solve(N, R, C):
    solve.case += 1
    if (R * C)%N != 0:
        # obvious necessary condition
        print "Case #%d: RICHARD" % solve.case
        return
    if N > 6:
        # get the one with a hole in the middle
        print "Case #%d: RICHARD" % solve.case
        return
    if (N+1)/2 > min(R, C) or N > max(R, C):
        # get either the L or the I shaped polyomino
        print "Case #%d: RICHARD" % solve.case
        return
    if min(R, C) >= 6:
        # conjecture: its always possible to place the piece
        # so that the remaining cells form a single component
        print "Case #%d: GABRIEL" % solve.case
        return

    # Solution for small case
    if N <= 3:
        print "Case #%d: GABRIEL" % solve.case
        return
    if min(R, C) <= 2:
        print "Case #%d: RICHARD" % solve.case
        return
    print "Case #%d: GABRIEL" % solve.case
    return

T = int(raw_input())
solve.case = 0

for t in xrange(1, T+1):
    N, R, C = map(int, raw_input().split())
    solve(N, R, C)
