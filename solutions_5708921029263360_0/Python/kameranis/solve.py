#!/usr/bin/env python

import numpy as np
import itertools

for i in xrange(int(raw_input())):
    J, P, S, K = [int(k) for k in raw_input().split()]
    combinations = []
    J_list = range(1, J+1)
    P_list = range(1, P+1)
    S_list = range(1, S+1)
    JP = np.zeros(J*P).reshape(J, P)
    PS = np.zeros(P*S).reshape(P, S)
    JS = np.zeros(J*S).reshape(J, S)
    for k, l, m in itertools.product(J_list, P_list, S_list):
        if JP[k-1, l-1] < K and PS[l-1, m-1] < K and JS[k-1, m-1] < K:
            JP[k-1, l-1] += 1
            PS[l-1, m-1] += 1
            JS[k-1, m-1] += 1
            combinations.append(' '.join((str(k), str(l), str(m))))
            # print 'JP', JP
            # print 'PS', PS
            # print 'JS', JS

    print "Case #{}: {}".format(i+1, len(combinations))
    for k in combinations:
        print k

