def check(x, r, c):
    if r > c:
        (r, c) = (c, r)
    if x == 1:
        return True
    elif x == 2:
        return r * c % 2 == 0
    elif x == 3:
        return (r, c) in [(2, 3), (3, 3), (3, 4)]
    elif x == 4:
        return (r, c) in [(3, 4), (4, 4)]

dat = int(raw_input())
for cas in xrange(1, dat + 1):
    x, r, c = map(int, raw_input().split())
    print "Case #%d: %s" % (cas, "GABRIEL" if check(x, r, c) else "RICHARD")
