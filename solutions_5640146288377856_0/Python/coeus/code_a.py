from math import floor
from sys import argv
lns = open(argv[1]).readlines()
for case, ln in enumerate(lns[1:]):
    r, c, w = ln.strip().split()
    if int(c)%int(w) == 0:
        result = int(r) * floor(float(c)/float(w)) + int(w) - 1
    else:
        result = int(r) * floor(float(c)/float(w)) + int(w)
    print 'Case #%d: %d' % (case+1, result)
