import sys
sys.setrecursionlimit(10000) 

read_ints = lambda: map(int, raw_input().split())
read_int  = input

for no_t in xrange(1, read_int() + 1):
    r, t = read_ints()
    lo, hi = 0, 10**18
    while lo + 1 < hi:
        md = (hi + lo) / 2
        if 2*r*md + md*(2*md-1) > t:
            hi = md
        else:
            lo = md
    print 'Case #%d: %s' % (no_t, lo)
