import sys
import time

getline = lambda: sys.stdin.readline().replace("\n", "")
getlist = lambda: getline().split(" ")
getint = lambda: int(getline())
getints = lambda: map(int, getlist())
PI = 3.1415

def go(y, r):
    return y*(2*r +1) + 2*y*(y-1)

for tc in xrange(1, 1+int(getline())):
    s = ""
    r, t = getints()
    cr = r
    y = 1
    area = 0
    i = 1
    last = 0
    while 1:
        last = y
        area = go(y*2, r)
        if area > t:
            break

        y *= 2
    left = y
    right = 2*y

    mid = (left + right) / 2
    while right - left > 1:
        mid = (left + right) / 2
        area = go(mid, r)
        if area < t:
            left = mid
        else:
            right = mid

    while go(left+1, r) <= t:
        left += 1


    print "Case #%d: %d" % (tc, left)


