T = int(raw_input().strip())

for i in range(1,T+1):
    K, C, S = map(int, raw_input().strip().split(' '))
    st = ' '.join(map(str, range(1, S+1)))
    print 'Case #%d: %s' % (i, st)