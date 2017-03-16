t = int(raw_input())
for cas in xrange(t):
    _, s = raw_input().split()
    now = cnt = 0
    for k, v in enumerate(map(int, list(s))):
        need = k - now
        if need > 0:
            cnt += need
            now += need
        now += v
    print 'Case #{0}: {1}'.format(cas+1, cnt)
