# only works for small
tt = int(raw_input())
for t in xrange(1, tt+1):
    (x, r, c) = map(int, raw_input().split())
    if x == 1:
        result = 'lose'
    elif (r * c) % x != 0:
        result = 'win'
    elif x == 2:
        result = 'lose'
    elif x == 3:
        result = 'win' if (r <= 1 or c <= 1) else 'lose'
    elif x == 4:
        result = 'win' if (r <= 2 or c <= 2) else 'lose'

    ans = 'RICHARD' if result == 'win' else 'GABRIEL'
    print 'Case #%d: %s' % (t, ans)