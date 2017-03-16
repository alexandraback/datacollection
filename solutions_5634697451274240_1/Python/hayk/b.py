import sys
import numpy as np

fin = sys.argv[1]
fout = sys.argv[2]

with open(fin) as fin, open(fout, 'w') as fout:
    t = int(fin.readline().strip())
    for i in xrange(1, t + 1):
        s = fin.readline().strip() + "+"
        n = s.count('-+') + s.count('+-')
        fout.write("Case #%d: %d\n" % (i, n))

