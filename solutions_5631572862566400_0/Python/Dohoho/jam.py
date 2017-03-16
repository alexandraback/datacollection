import itertools
import sys

n = int(raw_input())
for ii in xrange(n):
    raw_input()
    bf = map(lambda x: x-1, map(int, raw_input().split()))
    best = 0
    try:
        for i in range(len(bf), 0, -1):
            for l in itertools.permutations(range(len(bf)), i):
                bad = False
                for x in range(1, i-1):
                    if bf[l[x]] != l[x-1] and bf[l[x]] != l[x+1]:
                        bad = True
                        break
                if bad:
                    continue
                if bf[l[0]] != l[1] and bf[l[0]] != l[-1]:
                    continue
                if bf[l[-1]] != l[0] and bf[l[-1]] != l[-2:]:
                    continue
                best = i
                raise Exception
    except Exception:
        #print "Unexpected error:", sys.exc_info()[1]
        print "Case #%d: %d" % (ii+1, best)
        sys.stderr.write("%d\n" % (ii+1))