from __future__ import division
import math

with open('input', 'r') as f:
    num = int(f.readline().strip())
    for idx in xrange(num):
        pdiner = int(f.readline().strip())
        pancakes = map(int, f.readline().strip().split(' '))
        max_pancake = max(pancakes)
        final = max_pancake
        for i in xrange(1,max_pancake+1):
            tmp = i + sum([math.ceil(p/i) for p in pancakes]) - len(pancakes)
            if tmp < final:
                final = int(tmp)
        print 'Case #' + str(idx+1) + ': ' + str(final)
