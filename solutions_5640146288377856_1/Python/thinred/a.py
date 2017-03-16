
import sys

stdin = sys.stdin

T = int(stdin.readline().strip())

def solve(r, c, w):
    k = c // w
    if r == 1:
        if c % w == 0:
            return (k-1) + w
        else:
            return (k-1) + w + 1
    else:
        count = (r-1) * k
        return count + solve(1, c, w)

i = 1
for line in stdin:
    r, c, w = map(int, line.strip().split())
    h = solve(r, c, w)    
    print "Case #%d: %d" % (i, h)
    i += 1
