#!/usr/bin/env python

import time
import sys
import random

def debug(s):
    sys.stderr.write('DEBUG: ' + str(s) + '\n')
    pass

start_time = time.time()
for case_num in xrange(1, int(raw_input()) + 1):
    debug('Processing Case #%d' % (case_num,))
    N = int(raw_input())

    digits = [i for i in xrange(10)]
    last = 0
    if N > 0:
        while digits:
            last += N
            d = map(int, str(last))
            digits = [i for i in digits if i not in d]

    print "Case #{0}: {1}".format(case_num, last if last > 0 else "INSOMNIA")
    

debug("--- %s seconds ---" % (time.time() - start_time))
