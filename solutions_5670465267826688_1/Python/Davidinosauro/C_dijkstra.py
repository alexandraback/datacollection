#!/usr/bin/env python2
from __future__ import division, print_function

import sys
import math
from itertools import izip, tee
from pprint import pprint as pp
from collections import Counter, namedtuple
import operator as op

def dbg(*args, **kwargs):
    return
    kwargs['file'] = sys.stderr
    print('.', *args, **kwargs)


# sign in (1, -1), val in ('1', 'i', 'j', 'k')
class Q(namedtuple('BaseQ', ['sign', 'val'])):
    def __mul__(self, other):
        #print('.', end='')
        return _QuatMulTable[(self, other)]

    def __pow__(self, exp):
        exp = exp % 4  # x ** i == x ** (i%4), cioè  x ** 4 == 1 sempre

        if (self, exp) not in _QuatPowTable:
            res = _p1
            for i in xrange(exp):
                res = res * self
            _QuatPowTable[(self, exp)] = res

        return _QuatPowTable[(self, exp)]

    def __repr__(self):
        return ('+' if self.sign>0 else '-') + self.val

_1, _i, _j, _k = ('1', 'i', 'j', 'k')
_p1, _m1 = Q(1, _1), Q(-1, _1)
_pi, _mi = Q(1, _i), Q(-1, _i)
_pj, _mj = Q(1, _j), Q(-1, _j)
_pk, _mk = Q(1, _k), Q(-1, _k)

_QuatMulTable = {
    (_p1, _p1): _p1,
    (_pi, _p1): _pi,
    (_pj, _p1): _pj,
    (_pk, _p1): _pk,

    (_p1, _pi): _pi,
    (_pi, _pi): _m1,
    (_pj, _pi): _mk,
    (_pk, _pi): _pj,

    (_p1, _pj): _pj,
    (_pi, _pj): _pk,
    (_pj, _pj): _m1,
    (_pk, _pj): _mi,

    (_p1, _pk): _pk,
    (_pi, _pk): _mj,
    (_pj, _pk): _pi,
    (_pk, _pk): _m1,
}

# Extend the 4x4 multiplication table to 8x8 with all possible sign combinations
for s1 in (1, -1):
    for v1 in ('1', 'i', 'j', 'k'):
        for s2 in (1, -1):
            for v2 in ('1', 'i', 'j', 'k'):
                if (Q(s1, v1), Q(s2, v2)) not in _QuatMulTable.keys():
                    base = _QuatMulTable[(Q(1, v1), Q(1, v2))]
                    _QuatMulTable[(Q(s1, v1), Q(s2, v2))] = Q(
                        sign=(s1 * s2 * base.sign), val=base.val
                    )
#pp(_QuatMulTable)

#_QuatDivLTable[(x, y)] == Z  iff Z * y == x
#_QuatDivRTable[(x, y)] == Z  iff y * Z == x 
_QuatDivLTable = {}
_QuatDivRTable = {}

for ((x, y), prod) in _QuatMulTable.iteritems():
    if (prod, y) in _QuatDivLTable:
        assert False
    _QuatDivLTable[(prod, y)] = x

for ((x, y), prod) in _QuatMulTable.iteritems():
    if (prod, x) in _QuatDivRTable:
        assert False
    _QuatDivRTable[(prod, x)] = y

#pp(_QuatDivLTable)
_QuatPowTable = {}  # could fill it, but I only use it as a cache instead...

assert (set(_QuatDivLTable.keys()) == set(_QuatMulTable.keys()))
assert (set(_QuatDivRTable.keys()) == set(_QuatMulTable.keys()))


def subseq_prod(partial_prod_seq, a, b):
    'Return the product of terms from a (included) to b (excluded)'
    assert a>0 and b>0 and a <= b
    assert a-1 >= 0
    assert b-1 < len(partial_prod_seq)

    #  partial[a-1] * RESULT == partial[b]
    ret = _QuatDivRTable[(partial_prod_seq[b-1], partial_prod_seq[a-1])]

    dbg('between', a, 'and', b, ':', ret)
    return ret


def result_large(X, s):
    dbg(X, 'times', s, '(L={})'.format(len(s)))
    seq = tuple(Q(1, c) for c in s)

    # compute the partial products in both directions
    prod_lr = [None for _ in seq]
    accu = Q(1, '1')
    for i, x in enumerate(seq):
        accu = accu * x
        prod_lr[i] = accu

    prod_rl = [None for _ in seq]
    accu = Q(1, '1')
    for i, x in izip(xrange(len(seq)-1, -1, -1), reversed(seq)):
        accu = x * accu  # note reversed multiplication
        prod_rl[i] = accu

    dbg('prod_lr:', prod_lr)
    dbg('seq:    ', seq)
    dbg('prod_rl:', prod_rl)

    # check the total product is correct
    seq_prod = prod_lr[-1]
    tot_prod = seq_prod ** X
    if tot_prod != _m1:
        dbg('returning NO, because full product is not -1: ', prod_lr[-1])
        return 'NO'

    # look for a place where product is +i
    i_index = None
    for rep in range(min(4, X)):  # scan at most 4, then results will repeat
        for i, p in enumerate(prod_lr):
            if (seq_prod ** rep) * p == _pi:  # exponentiation has constant time
                i_index = i + rep * len(seq)
                break

        if i_index is not None:
            break

    if i_index is None:
        dbg('returning NO, because I couldnt find any i_index')
        return 'NO'

    # same, looking for +k backwards
    k_index = None
    for rep in range(min(4, X)):
        for i, p in izip(xrange(len(seq)-1, -1, -1), reversed(prod_rl)):
            if p * (seq_prod ** rep) == _pk:
                k_index = i + (X-1) * len(seq) - rep * len(seq)
                break

        if k_index is not None:
            break

    if k_index is None:
        dbg('returning NO, because I couldnt find any k_index')
        return 'NO'

    if i_index + 1 < k_index:
        dbg('FOUND!: ', i_index, k_index)
        return 'YES'
    else:
        dbg('returning NO, overlapping indices: ', i_index, k_index)
        return 'NO'


def result_small(X, s):
    dbg(X, 'times', s, '(L={})'.format(len(s)))
    seq = tuple(Q(1, c) for c in s)
    #dbg(seq)

    fullseq = X * seq

    accu = Q(1, '1')
    i_indices = []
    prod_lr = [None for _ in fullseq]
    for i, x in enumerate(fullseq):
        accu = accu * x
        prod_lr[i] = accu
        if accu == _pi:
            i_indices.append(i)

    accu = Q(1, '1')
    k_indices = []
    prod_rl = [None for _ in fullseq]
    for i, x in izip(xrange(len(fullseq)-1, -1, -1), reversed(fullseq)):
        accu = x * accu  # note reversed multiplication
        prod_rl[i] = accu
        if accu == _pk:
            k_indices.append(i)

    #dbg('prod_lr:', prod_lr)
    #dbg('full:   ', fullseq)
    #dbg('prod_rl:', prod_rl)

    #dbg('i_indices:', i_indices, 'k_indices:', k_indices)

    if prod_lr[-1] != _m1:
        dbg('returning NO, because full product is not -1: ', prod_lr[-1])
        return 'NO'

    # note  i_indices is increasing,  k_indices is decreasing

    if not i_indices:
        dbg('returning NO, because I couldnt find any i_index')
        return 'NO'
    if not k_indices:
        dbg('returning NO, because I couldnt find any k_index')
        return 'NO'

    # turns out that if there is at least one i_index and one k_index
    # that do not overlap, then the product in the middle area will always be j
    if i_indices[0] + 1 < k_indices[0]:
        return 'YES'
    else:
        return 'NO'

    if False:  # old code used for solving small...
        for i_index in i_indices:
            if i_index >= len(prod_lr) - 2:
                break

            for k_index in k_indices:
                # try cutting just after i_index and before k_index
                if i_index + 1 >= k_index:
                    break
                else:
                    # product up-to-i_index is i,  down-to-k_index is k
                    # what is the product of the middle section?
                    middle = subseq_prod(prod_lr, i_index + 1, k_index)
                    if middle == _pj:
                        dbg('FOUND!')
                        return 'YES'

        return 'NO'


if __name__ == '__main__':
    #sys.setrecursionlimit(max(2000, sys.getrecursionlimit()))
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        print('===', t+1, '===', file=sys.stderr)

        L, X = tuple(int(tk) for tk in sys.stdin.readline().strip().split())
        s = sys.stdin.readline().strip()

        #if t+1 != 8: continue
        res = result_large(X, s)
        print('Case #{}: {}'.format(t+1, res))
        sys.stdout.flush()

