t = int(raw_input())
for icase in range(1, t+1):
    n = int(raw_input())
    if n == 0:
        print 'Case #%d: INSOMNIA' % icase
    else:
        res = 0
        ds = set()
        while len(ds) < 10:
            res += n
            ds |= set(str(res))
        print 'Case #%d: %d' % (icase, res)
