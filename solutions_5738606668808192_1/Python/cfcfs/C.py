#!/usr/bin/env python

import time
import sys
import random

primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
        61,67,71,73,79,83,89,97,101,103,107,109,113,127,
        131,137,139,149,151,157,163,167,173,179,181,191,
        193,197,199,211,223,227,229,233,239,241,251,257,
        263,269,271]

def debug(s):
    sys.stderr.write('DEBUG: ' + str(s) + '\n')
    pass

start_time = time.time()
for case_num in xrange(1, int(raw_input()) + 1):
    debug('Processing Case #%d' % (case_num,))
    N, J = map(int, raw_input().split())
    results = {}

    for i in xrange(2**(N-2)):
        s = '1{0:{fill}{width}b}1'.format(i, fill="0", width=N-2)
        divisors = []
        for b in xrange(2,11):
            v = int(s,b)
            base_divisors = filter(lambda j: v % j == 0, primes)
            if not base_divisors:
                break
            divisors.append(base_divisors)
        if len(divisors) == 9:
            results[s] = map(lambda x: x[0], divisors)
        if len(results) >= J:
            break

    print "Case #{0}:".format(case_num)
    for i, (k, v) in enumerate(results.items()):
        debug(i)
        print "{0} {1}".format(k, ' '.join(map(str, v)))
        if i > J:
            break
    

debug("--- %s seconds ---" % (time.time() - start_time))
