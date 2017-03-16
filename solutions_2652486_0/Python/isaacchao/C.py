#! /usr/bin/env python
import sys, re
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getints = lambda: map(int, gettoken())


""" END TEMPLATE JCHAOISAAC """

# global data

def factorize(n):
    factors = []
    c = 0
    while n % 2 == 0: n, c = n / 2, c + 1
    if c != 0: factors.append((2, c))
    if n == 1: return factors
    for i in xrange(3, n + 1, 2):
        c = 0
        while n % i == 0: n, c = n / i, c + 1
        if c != 0: factors.append((i, c))
        if n == 1: break
    return factors

# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    print "Case #%d:" % (cases) # answer output

    R, N, M, K = getints()
    for _ in xrange(R):
        ks = getints()

        ans = {2: 0, 3: 0, 4: 0, 5: 0}
        c = 0

        fss = map(factorize, ks)
        for fs in fss:
            for (p, a) in fs:
                # no ambiguity
                if p == 3 or p == 5:
                    ans[p] = max(ans[p], a)

        needed = N - ans[3] - ans[5]

        max2 = 0
        sum2 = 0
        for fs in fss:
            for (p, a) in fs:
                if p != 2: continue
                
                max2 = max(max2, a)
                sum2 += a

        avg2 = sum2 / float(K)

        at_least_4 = max2 - needed

        best = None
        dist = []
        for b in xrange(max(0, at_least_4), needed + 1):
            a = needed - b

            if a < 0 or a > 2 * needed - max2:
                continue

            ndist = abs(2 * avg2 - (a + 2 * b))

            if ndist < dist:
                dist = ndist
                best = (a, b)

            #print (a, ans[3], b, ans[5])
        
        maybe_ans = ''.join(["2" * best[0], "3" * ans[3], "4" * best[1], "5" * ans[5]])
        #print best, dist
        print maybe_ans


                
        

    # main

