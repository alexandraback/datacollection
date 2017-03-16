#!/usr/bin/env python2
from __future__ import division, print_function

import sys
import math
from itertools import izip, tee
from pprint import pprint as pp
from collections import Counter, namedtuple
import operator as op


def dbg(*args, **kwargs):
    #return
    kwargs['file'] = sys.stderr
    print('.', *args, **kwargs)


# I'v drown on paper the non-trivial cases...
res_set = {
    (3, 2, 3): True,
    (3, 3, 3): True,
    (3, 3, 4): True,
    (4, 2, 4): False, # Z-shaped
    (4, 3, 4): True,
    (4, 4, 4): True,
}


def result_small(X, R, C):
    'True if Gabriel wins no matter Richard\'s choice'
    dbg(X, R, C)

    if R > C:
        R, C = C, R  # horizontal rectangle
    assert R <= C

    if X > R * C:  # No way
        dbg('lose by space')
        return False

    if X > max(R, C):  # Richard may choose the longest bar
        dbg('lose by bar')
        return False

    if (R * C) % X != 0:
        dbg('lose by non-exact division')
        return False

    # R may choose L shape and win
    if (X+1)//2 > R or math.ceil((X+1)/2) > C:
        dbg('lose by L')
        return False

    if X == 1:
        return True

    if X == 2:
        if R == 1:
            return (C % 2 == 0)
        elif R in (2, 4) or C in (2, 4):
            return True
        elif (C * R) % 2 == 1:
            return False

    if (X, R, C) not in res_set:
        dbg('MISSING:  {}: ,'.format((X, R, C)))
    else:
        return res_set[(X, R, C)]



if __name__ == '__main__':
    #sys.setrecursionlimit(max(2000, sys.getrecursionlimit()))
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        print('===', t+1, '===', file=sys.stderr)

        X, R, C = tuple(int(tk) for tk in sys.stdin.readline().strip().split())

        #if t+1 != 8: continue
        res = result_small(X, R, C)
        print('Case #{}: {}'.format(t+1, 'GABRIEL' if res else 'RICHARD'))
        sys.stdout.flush()

