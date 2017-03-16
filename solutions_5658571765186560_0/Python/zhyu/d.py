t = int(raw_input())
for cas in xrange(t):
    x, r, c = map(int, raw_input().split())
    total = r * c
    can = (total % x == 0)
    if can:
        can = (total / x) >= (x - 1)
    print 'Case #{0}: {1}'.format(cas+1, 'GABRIEL' if can else 'RICHARD')
