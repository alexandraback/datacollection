def digits_to_index(digs, base):
    rv = 0
    for dig in digs:
        rv *= base
        rv += dig
    return rv + 1

import sys
f = sys.stdin
T = int(f.readline())
for case in xrange(T):
    K, C, S = map(int, f.readline().split())
    if C * S < K:
        print "Case #%d: IMPOSSIBLE" % (case + 1,)
        continue
    indices = []
    for i in xrange(0, K, C):
        indices.append(digits_to_index(range(i, min(i + C, K)), K))
    print "Case #%d: " % (case + 1,) + " ".join(map(str, indices))
        