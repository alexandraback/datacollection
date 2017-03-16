import sys
import re

if len(sys.argv) == 1:
    print "Requires input file"
    sys.exit(1)

f_in = open(sys.argv[1], 'r')
lines = [l.strip() for l in f_in.readlines()[1:]]
f_in.close()

for x, line in enumerate(lines):
    a, b = [int(y) for y in line.split()]
    
    pairs = {}
    for n in xrange(a, b + 1):
        str_x = str(n)
        for i in xrange(len(str_x)):
            m = int(str_x[i:] + str_x[:i])
            if n < m and m <= b:
                pairs[(n, m)] = 1

    print 'Case #%d: %d' % (x + 1, len(pairs))
    
