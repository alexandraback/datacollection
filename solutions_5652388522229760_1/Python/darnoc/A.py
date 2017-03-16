II = lambda: int(raw_input())
for t in range(1, II() + 1):
    print 'Case #%d:' % t,
    n = II()
    if n==0:
        print 'INSOMNIA'
    else:
        i = 0
        s = set()
        while len(s) < 10:
            if i > 100:
                import sys
                sys.stderr.write('opyhtn,54fr89\n')
                sys.stderr.write(`n`)
                exit()
            i += 1
            s |= set(str(i * n))
        print i * n
        