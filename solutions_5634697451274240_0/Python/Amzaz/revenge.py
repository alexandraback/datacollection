
import sys
f = sys.stdin
T = int(f.readline())
for case in xrange(T):
    S = f.readline().strip()
    S += '+'
    count = 0
    for i in xrange(len(S) - 1):
        count += S[i] != S[i + 1]
    print "Case #%d: %d" % (case + 1, count)
        