import sys
import numpy as np

with open(sys.argv[1]) as fin, open(sys.argv[2], 'w') as fout:
    fin.readline()

    inp = np.loadtxt(fin).astype('int')
    for t in xrange(0, len(inp)):
        fout.write('Case #%d:' % (t + 1))

        [k, c, s] = inp[t]
        if c * s < k:
            fout.write(' IMPOSSIBLE\n')
            continue

        for ind in xrange(0, k, c):
            loc = 0
            i = ind
            d = 0
            while i < k and d < c:
                loc += i * k ** (c - d - 1)

                d += 1
                i += 1

            fout.write(' ' + str(loc + 1))

        fout.write('\n')

