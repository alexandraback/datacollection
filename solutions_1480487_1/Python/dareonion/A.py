#!/usr/bin/env python
import sys
from collections import defaultdict

def main(args):
    finname = '%s.in' % args[1]
    foutname = '%s.out' % args[1]
    with open(finname, 'r') as fin, open(foutname, 'w') as fout:
        T = int(fin.readline().strip())
        for i in xrange(1, T+1):
            nums = [int(n) for n in fin.readline().strip().split()]
            N = nums[0]
            scores = nums[1:]
            X = sum(scores)
            
            trimmed_scores = []
            zeroes = set()
            for j, s in enumerate(scores):
                if N*s > 2*X:
                    zeroes.add(j)
                else:
                    trimmed_scores.append(s)

            trimmed_N = len(trimmed_scores)
            trimmed_X = X+sum(trimmed_scores)
            trimmed_percs = []
            for s in trimmed_scores:
                trimmed_percs.append(100*(float(trimmed_X)/trimmed_N-(float(s)))/X)
            percs = []
            for j in xrange(len(scores)):
                if j in zeroes:
                    percs.append(0)
                else:
                    percs.append(trimmed_percs.pop(0))
            fout.write('Case #%s: %s\n' % (i, ' '.join(str(perc) for perc in percs)))
                
if __name__ == '__main__':
    status = main(sys.argv)
    sys.exit(status)
