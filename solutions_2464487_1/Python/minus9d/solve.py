import math

def get_paint(x, r):
    return 2 * x * x + x * (2 * r - 1);

def solve():
    v = map(int, raw_input().split())

    r = v[0]
    t = v[1]

    lo = 1
    hi = math.sqrt(t)
    ans = 0
    while 1:
        x = int((lo + hi) / 2)
        paint1 = get_paint(x, r)
        paint2 = get_paint(x+1, r)
        if (paint1 <= t and paint2 > t):
            ans = x
            break
        if paint1 > t:
            hi = x
            continue
        if paint2 <= t:
            lo = x
            continue
        
    return ans
    



T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
