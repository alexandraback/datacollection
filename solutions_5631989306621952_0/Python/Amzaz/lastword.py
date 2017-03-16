
import sys
f = sys.stdin
T = int(f.readline())
for case in xrange(1, T+1):
    s = f.readline().strip()
    rv = s[0]
    for c in s[1:]:
        if c >= rv[0]:
            rv = c + rv
        else:
            rv = rv + c
    print "Case #%d: %s" % (case, rv)
        