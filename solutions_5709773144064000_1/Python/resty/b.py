import sys
f = sys.stdin

def solve():
    (c, F, x) = map(float, f.readline().split(' '))
    ans = x / 2.0
    prepare = 0.0
    speed = 2.0
    while prepare <= ans:
        prepare += c / speed
        speed += F
        ans = min(ans, prepare + x / speed)
    return ans

cases = int(f.readline())
for t in range(cases):
    print "Case #%d: %.8f" % (t+1, solve())
