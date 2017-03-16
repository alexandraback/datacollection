def total_area(n):
    return n*(2*n+2*r-1);

def find_me(imin, imax):
    if imin > imax: return -1;
    mid = (imin+imax)/2
    ta = total_area(mid)
    if (t >= ta):
        if (t==ta or total_area(mid+1) > t):
            return mid
        return find_me(mid, imax)
    else:
        return find_me(imin, mid)

t = int(raw_input());
for T in range(t):
    r, t = [int(x) for x in raw_input().split()]
    print "Case #%d: %d" % (T+1, find_me(0, 1707106780))
