#!/usr/bin/python
# -*- coding: utf-8 -*-

from operator import *
from collections import *

sigma = '1ijk!IJK'

class quat(object):
    def __init__(self, s):
        if isinstance(s, str):
            self.d = sigma.index(s)
        elif isinstance(s, int):
            self.d = s
        else:
            assert False

    def __mul__(self, b):
        C = quat({
            0: '1ijk',
            1: 'i!kJ',
            2: 'jK!i',
            3: 'kjI!'
        }[abs(self).d][abs(b).d])
        return -C if (+self) ^ (+b) else C

    def __abs__(self):
        return quat(self.d % 4)

    def __neg__(self):
        return quat((self.d + 4) % 8)

    def __pos__(self):
        return self.d < 4

    def __repr__(self):
        return sigma[self.d]

    def __eq__(self, b):
        return self.d == b.d

    def __hash__(self):
        return hash(self.d)

def solve(X, s):
    s = map(quat, s)

    '''
    subs1 = set()
    for q in s:
        total = total * q
        subs1.add(total)
    '''

    total = quat('1')
    state = 0
    x = defaultdict(list)
    for q in s * X:
        x[state].append(q)
        total = total * q
        if state == 0 and total == quat('i'):
            state = 1
        elif state == 1 and total == quat('k'):
            state = 2
    if state == 2 and total == quat('!'):
        #print dict(x)
        return 'YES'
    return 'NO'


T = int(raw_input())
for i in range(T):
    L, X = map(int, raw_input().split())
    s = raw_input()
    print "Case #%i: %s" % (i+1, solve(X, s))
