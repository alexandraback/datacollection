from fractions import Fraction

tc = int(raw_input())
for caso in range(1, tc+1):
    print 'Case #%d:' % (caso),
    n, d = [int(x) for x in raw_input().split('/')]
    v = Fraction(n, d)
    t = Fraction(1, 2)
    ans = -1
    for i in range(1, 41):
        if t <= v:
            v -= t
            if ans == -1:
                ans = i
        t /= 2
    if (v == 0):
        print ans
    else:
        print 'impossible'
