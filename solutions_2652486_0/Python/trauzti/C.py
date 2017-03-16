import itertools
import random
import sys

getline = lambda: sys.stdin.readline().replace("\n", "")
getlist = lambda: getline().split(" ")
getint = lambda: int(getline())
getints = lambda: map(int, getlist())


for t in xrange(1, 1+int(getline())):
    R, N, M, K = getints()
    l = []
    for r in xrange(R):
        q = getints()
        l.append(q)
    NUMS = range(2, M+1)
    possible = [j for j in itertools.product(NUMS, repeat=N)]
    print "Case #%d:" % t
    for prods in l:
        """
        for prod in prods:
            if prod > 1:
                d = {x : 0 for x in NUMS}
                for test in NUMS:
                    if prod % test == 0:
                        d[test] = 1
        """
        nums = random.choice(possible)
        print ''.join(map(str, nums))


