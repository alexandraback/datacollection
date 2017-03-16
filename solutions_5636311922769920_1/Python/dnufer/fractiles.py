__author__ = 'David'

import sys
import math

T = int(sys.stdin.readline())

'''
# Small input
for N in xrange(T):
    k, c, s = [int(x) for x in sys.stdin.readline().strip().split(' ')]

    looks = []
    pos = 1
    step = k ** c / k
    while pos <= k ** c:
        looks.append(str(pos))
        pos += step

    print "Case #%d: %s" % (N + 1, ' '.join(looks))
'''

# Lager input
for N in xrange(T):
    k, c, s = [int(x) for x in sys.stdin.readline().strip().split(' ')]

    min_s = int(math.ceil(float(k) / c))

    if s < min_s:
        print "Case #%d: IMPOSSIBLE" % (N + 1)
        continue
    if c == 1:
        print "Case #%d: %s" % (N + 1, ' '.join([str(s + 1) for s in xrange(k)]))
        continue

    looks = []
    for i in xrange(0, k, c):
        x = ((2 ** k) + i) % k
        if x == 0:
            x = k
        x += k * i
        looks.append(str(x))

    if len(looks) > min_s:
        looks = looks[:min_s]

    print "Case #%d: %s" % (N + 1, ' '.join(looks))
