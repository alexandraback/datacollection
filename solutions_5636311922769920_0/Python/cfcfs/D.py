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
    K, C, S = map(int, raw_input().split())
    tiles = []

    ng = 0
    for j in xrange(C):
        ng += (K**(C-j-1)) * ((K-1)**j)
    debug("K="+str(K))
    debug("C="+str(C))
    debug("S="+str(S))
    debug("ng="+str(ng))
    debug("ng*S="+str(ng*S))
    debug("K**C="+str(K**C))
    debug("decision="+"OK" if ng * S >= K**C else "IMPOSSIBLE")
    debug("over="+str(K / S if K > S else 0))
    if ng * S < K**C:
        print "Case #{0}: IMPOSSIBLE".format(case_num)
        continue
    else: 
        over = K / S if K > S else 0
    
    # solution for K = S
    tiles = [i for i in xrange(K)]
    debug(tiles)
    for c in xrange(1, C):
        tiles = [(K**c)*i+j for i,j in enumerate(tiles)]
        debug(tiles)

    if over > 0:
        t2 = []
        for i in xrange(over):
            t2.append((i+1)*(K**(C-1))-i-1)
        tiles = t2 + tiles[over:-over]

    tiles = map(lambda x: x+1, tiles)
    print "Case #{0}: {1}".format(case_num, ' '.join(map(str, tiles)))

debug("--- %s seconds ---" % (time.time() - start_time))
