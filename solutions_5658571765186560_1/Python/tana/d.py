tt = int(raw_input())
for t in xrange(1, tt+1):
    (x, r, c) = map(int, raw_input().split())
    if x == 1:
        result = 'lose'
    elif (r * c) % x != 0 or x >= 7:
        result = 'win'
    elif x >= 6:
        result = 'win' if min(r, c) + 3 <= x else 'lose'
    else:
        result = 'win' if min(r, c) + 2 <= x else 'lose'

    ans = 'RICHARD' if result == 'win' else 'GABRIEL'
    print 'Case #%d: %s' % (t, ans)