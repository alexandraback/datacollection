T = int(raw_input().strip())

for i in range(T):
    N = int(raw_input().strip())
    if N == 0:
        print 'Case #%d: INSOMNIA' % (i+1)
        continue
    maxtimes = int('1' + len(str(N))*2* '0')
    num = 'INSOMNIA'
    digs = set()
    for d in xrange(1,maxtimes):
        thisnum = str(d*N)
        for c in thisnum:
            digs.add(c)
        if len(digs) >= 10:
            num = thisnum
            break
    print 'Case #%d: %s' % (i+1, num)