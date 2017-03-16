from decimal import *

fn = 'A-small-attempt0'
fi = open('%s.in' % fn,'r')
fo = open('%s.out' % fn,'w')
t = int(fi.readline())
lines = fi.readlines()
fi.close()

for i in range(t):
    [a, b] = map(lambda x: int(x), lines[i*2].split(' '))
    ps = map(lambda x: Decimal(x), lines[i*2 +1].split(' '))
    expected = b + 1 + 1
    cases = range(a+1)
    cases.reverse()
    allcorrect_before_b = Decimal('1')
    ks1 = b + 1 - a
    ksa = b + 1
    for j in cases:
        min_keystroke = ks1 + 2 * j
        p1 = allcorrect_before_b * min_keystroke
        p2 = (Decimal('1') - allcorrect_before_b) * (min_keystroke + ksa)
        p = p1 + p2
        if p < expected:
            expected = p
        # update allcorrect_before_b
        if j!=0:
            allcorrect_before_b = allcorrect_before_b * ps[a - j]
    

    print "Case #%s: %.6f" % ((i+1), round(expected,6))
    fo.write("Case #%s: %.6f\n" % ((i+1), round(expected,6)))
    
fo.close()
