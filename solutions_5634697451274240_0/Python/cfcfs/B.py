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
    S = raw_input()
    turns = 0
    s = '+'
    for i in S[::-1]:
        if i != s:
            turns += 1
            s = '+' if s == '-' else '-'

    print "Case #{0}: {1}".format(case_num, turns)
    

debug("--- %s seconds ---" % (time.time() - start_time))
