import sys
import fractions

inp = sys.stdin.read().splitlines()

N = int(inp[0])
for i in xrange(N):
    fr = fractions.Fraction(inp[i+1])
    res = -1
    if fr.denominator in [2**j for j in xrange(41)]:
        for n in xrange(41):
            if fr >= fractions.Fraction(1, 2**n):
                res = n
                break
    if res == -1:
        print 'Case #%d: impossible' % (i+1)
    else:
        print 'Case #%d: %d' % (i+1, res)
