import math

def needed_paint(r, n):
    return (n+1)*(2*n + 2*r +1)


cases = int(raw_input())
for case in xrange(cases):
    r, t = [int(x) for x in raw_input().split()]

    hi = t
    lo = 0
    # print "looking for", t


    while lo < hi:
        mid = (lo+hi)//2
        # print "lo={} hi={} mid={} needed={} if={}".format(lo, hi, mid, needed_paint(r, mid), needed_paint(r, mid) < t)
        if needed_paint(r, mid) <=t:
            lo = mid+1
        else:
            hi = mid

    result = lo


    print "Case #{}: {}".format(case+1, result)

