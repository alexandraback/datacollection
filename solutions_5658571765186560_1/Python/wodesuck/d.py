def check(x, r, c):
    if r > c:
        (r, c) = (c, r)
    if x == 1:
        return True
    elif x == 2:
        return r * c % 2 == 0
    elif x == 3:
        return r * c % 3 == 0 and r >= 2 and c >= 3
    elif x == 4:
        return r * c % 4 == 0 and r >= 3 and c >= 4
    elif x == 5:
        return r * c % 5 == 0 and r >= 4 and c >= 5
    elif x == 6:
        return r * c % 6 == 0 and r >= 4 and c >= 6
    else:
        return False

dat = int(raw_input())
for cas in xrange(1, dat + 1):
    x, r, c = map(int, raw_input().split())
    print "Case #%d: %s" % (cas, "GABRIEL" if check(x, r, c) else "RICHARD")
