import sys
import itertools

t = int(raw_input())

for ii in xrange(t):
    n = int(raw_input())
    a = [int(i)-1 for i in raw_input().split(" ")]
    res = 0
    for x in xrange(1, n+1):
        for c in itertools.combinations(xrange(n), x):
            c = list(c)
            works2 = False
            for p in itertools.permutations(c[1:]):
                p = [c[0]] + list(p)
                works = True
                for i in xrange(x):
                    if p[(i-1)%x] != a[p[i]] and p[(i+1)%x] != a[p[i]]:
                        works = False
                        break
                if works:
                    works2 = True
                    break
            if works2:
                res = x
                break
    print "Case #%d: %d" % (ii+1, res)
    sys.stdout.flush()
