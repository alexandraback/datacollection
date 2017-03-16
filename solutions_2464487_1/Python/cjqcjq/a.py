import sys
def f(k, r):
    return (k + 1) * (2 * r + 2 * k + 1)
lines = open(sys.argv[1], 'r').readlines()
for i in range(1, len(lines)):
    r, t = lines[i][0:-1].split(' ')
    r = int(r)
    t = int(t)
    lw = 0
    hi = t
    while lw <= hi:
        mid = (lw + hi) / 2
        if f(mid, r) <= t:
            lw = mid + 1
        else:
            hi = mid - 1
    print 'Case #' + str(i) + ': ' + str(hi + 1)
