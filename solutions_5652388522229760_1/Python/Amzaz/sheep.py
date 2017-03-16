def add_digs(n, digs):
    while n > 0:
        digs.add(n % 10)
        n /= 10

import sys
f = sys.stdin
T = int(f.readline())
for case in xrange(T):
    N = int(f.readline())
    if N == 0:
        print "Case #%d: INSOMNIA" % (case + 1,)
        continue
    curr = N
    digs = set()
    while len(digs) != 10:
        add_digs(curr, digs)
        curr += N
    print "Case #%d: %d" % (case + 1, curr - N)
        