import sys
import time

sys.stdin.readline()
for tc, line in enumerate(sys.stdin):
    v = [int(n) for n in line.strip().split()]
    a, b = v
    recycled = set()
    for i in range(a, b + 1):
        s = str(i)
        for j in xrange(1, len(s)):
            if s[j] <= s[0]:
                candidate = int(s[j:] + s[:j])
                if a <= candidate < i:
                    recycled.add((i, candidate))
    print "Case #%d: %d" % (tc + 1, len(recycled))
    
    
    