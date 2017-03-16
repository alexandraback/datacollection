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
    print('.', *args, **kwargs)


def divide_biggest(diners_by_size, factor):
    assert diners_by_size[-1] > 0

    max_cnt = len(diners_by_size) - 1
    ret = diners_by_size[:-1]
    half = max_cnt / factor
    h1 = int(math.floor(half))  # XXX: floor or ceil??
    h2 = max_cnt - h1
    ret[h1] += diners_by_size[-1]
    ret[h2] += diners_by_size[-1]

    return ret


def best(diners_by_size, prefix=''):
    dbg(prefix, list(enumerate(diners_by_size))[1:])
    i = 0
    while diners_by_size[-1 - i] == 0:
        i += 1
    if i > 0:
        diners_by_size = diners_by_size[:-i]

    dbg(prefix, list(enumerate(diners_by_size))[1:])

    max_cnt = len(diners_by_size) - 1
    assert max_cnt > 0
    dbg(prefix, 'max_cnt', max_cnt)
    if max_cnt == 1:
        return max_cnt

    if max_cnt < diners_by_size[-1]:
        dbg(prefix, 'surely normal:', max_cnt)
        return max_cnt

    dbg(prefix, 'normally:', max_cnt)

    best_so_far = max_cnt
    for i in range(2, max_cnt):
        dbg('by', i, '?')
        current = (diners_by_size[-1]
                   + best(divide_biggest(diners_by_size, i), prefix+' .'))
        if current < best_so_far:
            best_so_far = current
            dbg(prefix, 'dividing by', i, 'is better:', current)
        else:
            break

    dbg(prefix, 'returning:', best_so_far)

    return best_so_far


def result(N, p):
    dbg(N, p)
    diners_cnt = Counter(p)
    max_cnt = max(p)
    diners_by_size = [0 for _ in range(max_cnt+1)]
    for i in range(1, max_cnt+1):
        diners_by_size[i] = diners_cnt[i]


    return best(diners_by_size)


if __name__ == '__main__':
    #sys.setrecursionlimit(max(2000, sys.getrecursionlimit()))
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        print('===', t+1, '===', file=sys.stderr)

        N, = tuple(int(tk) for tk in sys.stdin.readline().strip().split())
        p = tuple(int(tk) for tk in sys.stdin.readline().strip().split())

        res = result(N, p)
        print('Case #{}: {}'.format(t+1, res))
        sys.stdout.flush()

