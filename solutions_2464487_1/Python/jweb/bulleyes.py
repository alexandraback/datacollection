import sys
import math

for tc in xrange(1, int(sys.stdin.readline())+1):
    r, t = [int(w) for w in sys.stdin.readline().split()]

    required_area = lambda n: n * (2 * r + 2 * n - 1)

    st_n = 1
    ed_n = int(math.sqrt(t))
    n = 1
    while True:
        n = st_n + (ed_n - st_n) / 2
        #print st_n, ed_n, n, required_area(n)
        if t >= required_area(n):
            st_n = n
        elif t <= required_area(n):
            ed_n = n
        if ed_n - st_n < 100:
            break
    for k in range(st_n, ed_n + 1):
        if required_area(k) <= t:
            n = k
        else:
            break
    #print st_n, ed_n
    print 'Case #%d: %d' % (tc, n)
