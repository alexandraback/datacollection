__author__ = 'David'

import sys

T = int(sys.stdin.readline())

for N in xrange(T):
    n = int(sys.stdin.readline())

    if n == 0:
        print "Case #%d: INSOMNIA" % (N + 1)
        continue

    #print
    digits = set()
    total = 0
    while len(digits) < 10:
        total += n
        _ = [digits.add(x) for x in str(total)]
        #print n, digits

    print "Case #%d: %d" % (N + 1, total)
