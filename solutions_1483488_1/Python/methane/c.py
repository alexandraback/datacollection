
def recnum(a, b):
    bs = str(b)
    c = 0
    for n in xrange(a, b):
        n = str(n)
        m = n[1:]+n[0]
        while n != m:
            if n < m <= bs:
                #print n,m
                c += 1
            m = m[1:]+m[0]
    return c

#print recnum(1, 9)
#print recnum(10, 40)
#print recnum(100, 500)
#print recnum(1111, 2222)
#print recnum(1000000,2000000)
#print recnum(100000 ,999999 )

import sys

sys.stdin.readline()

for i, L in enumerate(sys.stdin):
    a, b = map(int, L.split())
    print "Case #%d: %d" % (i+1, recnum(a, b))
