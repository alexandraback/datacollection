T = int(raw_input().strip())

for i in xrange(T):
    R, C, W = map(int, raw_input().strip().split(' '))
    if R > 1:
        needed = (R - 1) * (C / W)
    else:
        needed = 0

    needed += C / W

    if C % W == 0:
        needed += W - 1
    else:
        needed += W

    print "Case #%s: %s" % (i + 1, needed)


"""
    _ _ x _ _

    _ _ x x x

    _ x x x _

    x x x _ _




    _ _ _ x _ _ _

    _ _ _ x x x x

    _ _ x x x x _

    _ x x x x _ _

    x x x x _ _ _
"""

