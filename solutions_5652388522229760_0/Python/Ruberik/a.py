T = int(raw_input())

for i in range(1, T+1):
    N = int(raw_input())
    seen = set()
    print 'Case #%d:' % i,
    for x in range(1, 1001):
        xx = N*x
        seen = seen | set(str(xx))
        if len(seen) == 10:
            print xx
            break
    else:
        print 'INSOMNIA'

