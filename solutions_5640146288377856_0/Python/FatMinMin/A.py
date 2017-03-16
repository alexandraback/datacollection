T = int(raw_input())

for ca in xrange(1, T + 1):
    r, c, w = map(int, raw_input().split())
    ans = (c / w) + (w - 1) + (1 if c % w != 0 else 0)
    print 'Case #{}: {}'.format(ca, ans)
