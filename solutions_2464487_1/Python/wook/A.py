
import sys

rl = sys.stdin.readline

def able(R, r, t):
    required = 2 * R * (R+1) + (2*r - 3) * R
    return required <= t

def go(r, t):
    # first, we need (r+1)^2 - r^2 = r^2+2r+1 - r^2 = 2r+1
    # (r+3)^2 - (r+2)^2  = 6r+ 9 - 4r - 4 = 2r + 5
    # (r+5)^2 - (r+4)^2  = 10r + 25 - 8r - 16 = 2r + 9
    # (r+7)^2 - (r+6)^2  = 2r + (49-36) = 2r + 13
    # (r+9)^2 - (r+8)^2 = 2r + 81-64 = 2r+17

    lb = 1
    rb = t
    ans = None
    while lb <= rb:
        m = (lb+rb) / 2
        if able(m, r, t):
            ans = m
            lb = m + 1
        else:
            rb = m - 1
    return ans

T = int(rl())
for tt in xrange(1,T+1):
    r, t = map(int, rl().split())
    print "Case #%d: %d" % (tt, go(r, t))

