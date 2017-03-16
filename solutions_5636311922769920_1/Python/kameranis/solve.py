#!/usr/bin/env python

import numpy as np
import math

for i in xrange(input()):
    K, C, S = [int(k) for k in raw_input().split()]
    if K > C*S:
        print "Case #{}: IMPOSSIBLE".format(i+1)
        continue
    elif C == 1:
        print "Case #{}:".format(i+1), ' '.join(map(str, range(1, K+1)))
    else:
        points = int(math.ceil(float(K) / C))
        powers = np.array([K**k for k in range(C)][::-1])
        remain = np.array([k % K for k in range(points * C)])
        final = []
        for k in range(points):
            final.append(powers.dot(remain[C*k:C*(k+1)])+1)
        print "Case #{}:".format(i+1), ' '.join(map(str, final))


