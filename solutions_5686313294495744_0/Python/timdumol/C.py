#-*- encoding: utf-8 -*-

from __future__ import print_function
from __future__ import absolute_import
from __future__ import unicode_literals
from __future__ import division

import numpy as np
from itertools import permutations

n_cases = int(input())

for ctr in range(n_cases):
    n = int(input())
    imat = [tuple(input().split()) for _ in range(n)]

    mat = np.zeros((n, 2), dtype=np.int32)
    mapping = dict()
    n_uniq = 0
    for i in range(n):
        if imat[i][0] not in mapping:
            mapping[imat[i][0]] = n_uniq
            n_uniq += 1
        mat[i][0] = mapping[imat[i][0]]
        if imat[i][1] not in mapping:
            mapping[imat[i][1]] = n_uniq
            n_uniq += 1
        mat[i][1] = mapping[imat[i][1]]

    most_fake = 0
    for mask in range(1 << n):
        n_fake = 0
        fake = np.zeros(n, dtype=np.int8)
        for idx in range(n):
            if (mask >> idx) & 1:
                fake[idx] = 1
                n_fake += 1

        firsts = np.zeros(n_uniq, dtype=np.int8)
        seconds = np.zeros(n_uniq, dtype=np.int8)
        ok = True
        for i in range(n):
            if not fake[i]:
                firsts[mat[i][0]] = 1
                seconds[mat[i][1]] = 1
        for i in range(n):
            if not firsts[mat[i][0]] or not seconds[mat[i][1]]:
                ok = False
                break
        if ok:
            most_fake = max(n_fake, most_fake)

    print('Case #%d: %d' % (ctr+1, most_fake))
