#!/usr/bin/env python
import sys
from collections import defaultdict
from operator import itemgetter

def main():

    fname, gname = sys.argv[1:]
    with open(fname) as f, open(gname, 'w') as g:
        T = int(f.readline().strip())
        R, N, M, K = map(int, f.readline().strip().split())
        d = defaultdict(lambda: defaultdict(int))
        for i in xrange(2, M+1):
            for j in xrange(i, M+1):
                for k in xrange(j, M+1):
                    tup = (i, j, k)
                    d[1][tup] += 1
                    d[i][tup] += 1
                    d[j][tup] += 1
                    d[k][tup] += 1
                    d[i*j][tup] += 1
                    d[i*k][tup] += 1
                    d[j*k][tup] += 1
                    d[i*j*k][tup] += 1
        g.write("Case #1:\n")
        for i in xrange(R):
            products = map(int, f.readline().strip().split())

            tup_probs = {}
            for tup, prob in d[products[0]].iteritems():
                tup_probs[tup] = prob
            tups = set(tup_probs)

            for product in products[1:]:
                for tup in tups:
                    tup_probs[tup] *= d[product][tup]

            print [(tup, prob) for tup, prob in tup_probs.iteritems() if prob]
            result = max(tup_probs.iteritems(), key=itemgetter(1))[0]
            to_write = ''.join(map(str, result))
            g.write("{0}\n".format(to_write))

if __name__ == "__main__":
    status = main()
    sys.exit(status)
