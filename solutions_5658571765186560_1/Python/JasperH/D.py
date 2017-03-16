def solve():
    x,r,c = [int(x) for x in raw_input().split()]
    if x >= 7: return False
    if (r * c) % x != 0: return False
    # Values determined by hand
    if x == 1: return True
    elif x == 2: return True
    elif x == 3: return r > 1 and c > 1
    elif x == 4: return r > 2 and c > 2
    elif x == 5:
        l, h = min(r, c), max(r, c)
        return (l == 3 and h >= 10) or l > 3
    else:
        assert x == 6
        return r > 3 and c > 3

for i in range(int(raw_input())):
    print "Case #%d: %s"%(i+1, "GABRIEL" if solve() else "RICHARD")
