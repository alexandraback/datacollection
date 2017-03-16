t = int(raw_input())

for tt in xrange(1, t + 1):
    s = raw_input().replace('?', '{}')
    n = s.count('{')
    mn = (1000, '1000', '1000')
    for i in xrange(10 ** n, (10 ** n) * 2):
        s1, s2 = s.format(*list(str(i)[1:])).split(' ')
        si1, si2 = map(int, [s1, s2])
        s0 = abs(si1 - si2)
        cur = s0, s1, s2
        if map(int, mn) > map(int, cur):
            mn = cur
    print 'Case #{}: {} {}'.format(tt, *mn[1:])
