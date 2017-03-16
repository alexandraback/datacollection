
import sys

stdin = sys.stdin

T = int(stdin.readline().strip())

i = 1
for line in stdin:
    r, c, w = map(int, line.strip().split())
    if r == 1:
        k = c // w
        if c % w == 0:
            h = (k-1) + w
        else:
            h = (k-1) + w + 1
    print "Case #%d: %d" % (i, h)
    i += 1
