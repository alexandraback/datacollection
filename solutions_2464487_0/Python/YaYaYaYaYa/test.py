import math
import decimal

T = int(raw_input())
for i in xrange(T):
    tttt = raw_input().split()
    r = int(tttt[0])
    t = int(tttt[1])
    if r > 60000:
        x = -1
        while t > 0:
            t -= 2 * r + 1
            x += 1
    else:
        x = (-1.5 + math.sqrt(2.25 + (r * r - r + 2 * t - 2)))
        x = (x - r) / 2 + 1
    print "Case #%d: %d" % (i + 1, x)
