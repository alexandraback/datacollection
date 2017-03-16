import sys
 
cases = int(raw_input())
for c in xrange(cases):
    # read in misc problem constants
    x, y = map(str, raw_input().split())
 
    m = 0
    x = int(x)
    s = int(y[0])
    for i in xrange(1, x+ 1):
        if (i > s):
            m = max(m, i - s)
        s = s + int(y[i])
   
    print "Case #%d: %d" % ((c+1), m)