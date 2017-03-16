#!/usr/bin/env python

import time
import sys
import random

def debug(*args, **kwargs):
    if args:
        sys.stderr.write('DEBUG: ' + (';'.join(['{0}'.format(str(v)) for v in args])) + '\n')
    if kwargs:
        sys.stderr.write('DEBUG: ' + (';'.join(['{0}:{1}'.format(k, str(v)) for k, v in kwargs.items()])) + '\n')
    pass

start_time = time.time()
for case_num in xrange(1, int(raw_input()) + 1):
    debug('Processing Case #%d' % (case_num,))
    N = int(raw_input())
    debug(N=N)
    counter = {}
    for n in xrange(2*N-1):
        line = map(int, raw_input().split())
        for i in line:
            counter[i] = counter.get(i, 0) + 1
    debug(counter=counter)
    res = sorted([n for (n,c) in counter.items() if c % 2 == 1])
    
    print "Case #{0}: {1}".format(case_num, ' '.join(map(str, res)))

debug("--- %s seconds ---" % (time.time() - start_time))
