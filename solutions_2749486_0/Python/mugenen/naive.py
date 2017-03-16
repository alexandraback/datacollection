import sys

T = int(raw_input())
for i in xrange(1, T + 1):
    x, y = map(int, raw_input().split())
    route = ''
    while x != 0:
        if x > 0:
            route += 'EW'
            x -= 1
        else:
            route += 'WE'
            x += 1
    while y != 0:
        if y > 0:
            route += 'NS'
            y -= 1
        else:
            route += 'SN'
            y += 1
    print "Case #{0}: {1}".format(i, route[::-1])

