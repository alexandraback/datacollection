import numpy



lets = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

mat = [[lets[i].count(chr(ord('A')+x)) for i in xrange(10)] for x in xrange(26)]
T = input()
for t in xrange(1, T+1):
    print 'Case #{}:'.format(t),
    s = raw_input()
    b = [s.count(chr(ord('A')+x)) for x in xrange(26)]
    ans = numpy.linalg.lstsq(mat, b)[0]
    print ''.join(str(x)*int(round(ans[x])) for x in xrange(10))
