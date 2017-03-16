#!/usr/bin/env python2
from __future__ import division, print_function

import sys
import math
from itertools import izip, tee
from pprint import pprint as pp
from collections import Counter
import operator as op

def dbg(*args, **kwargs):
    return
    kwargs['file'] = sys.stderr
    print(*args, **kwargs)


def result(N, s):
    standing = 0
    friends = 0
    dbg(s)
    for shiness, count in enumerate(s):
        if standing < shiness:
            friends += (shiness - standing)
            standing += (shiness - standing)
        standing += count
        
    return friends


if __name__ == '__main__':
    #sys.setrecursionlimit(max(2000, sys.getrecursionlimit()))
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        print('===', t+1, '===', file=sys.stderr)

        N, s = tuple(tk for tk in sys.stdin.readline().strip().split())
        N = int(N)
        s = tuple(int(c) for c in s)

        res = result(N, s)
        print('Case #{}: {}'.format(t+1, res))
        sys.stdout.flush()

