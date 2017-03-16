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
    S = raw_input()
    debug(S=S)
    res = S[0]
    for c in S[1:]:
        if c >= res[0]:
            res = c + res
        else:
            res = res + c
    
    print "Case #{0}: {1}".format(case_num, res)

debug("--- %s seconds ---" % (time.time() - start_time))
