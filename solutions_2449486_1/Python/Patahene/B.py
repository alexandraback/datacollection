#!/usr/bin/env python

import itertools
import os.path as path
from collections import namedtuple, Counter
import pprint
import numpy as np # Numpy is a third party library. http://www.numpy.org/


def read_testcase(f):
    board = []
    N, M = map(int, f.readline().split())
    a = []
    for i in xrange(N):
        a.append(map(int, f.readline().split()))

    return N, M, np.array(a)

def solve(NMa):
    N, M, a = NMa

    hs = set([])
    for row in a:
        hs |= set(row)
    a = np.array(a)

    hl = sorted(list(hs), reverse=True)
    cur = hl[0]*np.ones(N*M, dtype=np.int32).reshape(N, M)

    for h in hl[1:]:
        for i in xrange(N):
            if not np.any(a[i] > h):
                cur[i] = h
        for i in xrange(M):
            if not np.any(a[:, i] > h):
                cur[:, i] = h

    if np.count_nonzero(a == cur) == a.size:
        ret = 'YES'
    else:
        ret = 'NO'
    return ret

if __name__ == '__main__':
    ans = []
    with open('B-large.in') as f:
        T = int(f.readline())
        print 'T =',T
        for i in xrange(T):
            print i
            ans.append(solve(read_testcase(f)))

    with open('ans.txt', 'w') as f:
        for i, a in enumerate(ans, start=1):
            f.write('Case #%d: %s\n'%(i, a))

