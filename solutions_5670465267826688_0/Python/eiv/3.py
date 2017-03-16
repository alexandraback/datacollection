#!/usr/bin/env python

import sys

class Q:
    def __init__(self, n, neg=1):
        self.n = n
        self.neg = neg
    def __mul__(self, Q2):
        sign = self.neg * Q2.neg
        if self.n == '1': return Q(Q2.n, sign)
        if Q2.n == '1': return Q(self.n, sign)
        if self.n == 'i':
            if Q2.n == 'i': return Q('1', -sign)
            if Q2.n == 'j': return Q('k', sign)
            if Q2.n == 'k': return Q('j', -sign)
        if self.n == 'j':
            if Q2.n == 'i': return Q('k', -sign)
            if Q2.n == 'j': return Q('1', -sign)
            if Q2.n == 'k': return Q('i', sign)
        if self.n == 'k':
            if Q2.n == 'i': return Q('j', sign)
            if Q2.n == 'j': return Q('i', -sign)
            if Q2.n == 'k': return Q('1', -sign)
    def __repr__(self):
        return ('-' if self.neg == -1 else '') + self.n

def lookForBegin(S, quat):
    res = []
    my = Q('1')
    for i,q in enumerate(S):
        my = my * Q(q)
        if my.n == quat and my.neg == 1: res.append(i)
    return res

def lookForEnd(S, quat):
    res = []
    my = Q('1')
    N = len(S) - 1
    for i,q in enumerate(reversed(S)):
        my = Q(q) * my
        if my.n == quat and my.neg == 1: res.append(N - i)
    res.reverse()
    return res


def checkMul(S, quat, start=0, end=None, neg=(1,)):
    if end is None: end = len(S)
    my = Q('1')
    for i in range(start, end):
        q = S[i]
        my = my * Q(q)
    return (my.n in quat and my.neg in neg)

def getMul(S):
    my = Q('1')
    for q in S: my = my * Q(q)
    return my

from collections import defaultdict
def getUnitIntervals(S):
    res = defaultdict(list)
    my = Q('1')
    state = (my.n, my.neg)
    res[state] = [0]
    for i,q in enumerate(S):
        my = my * Q(q)
        state = (my.n, my.neg)
        res[state].append(i+1)
    return res
    
def solve(S, X):
    mul = getMul(S)
    
    if X % 2 == 0:
        if X % 4 == 0 or (mul.n not in 'ijk'): return 'NO'
    else:
        if not (mul.n == '1' and mul.neg == -1): return 'NO'

    S = S * X
    #intervals = getUnitIntervals(S)

    iEnds = lookForBegin(S, 'i')
    if not iEnds: return 'NO'
    kBegins = lookForEnd(S, 'k')
    if not kBegins: return 'NO'
    for iend in iEnds:
        for kbegin in kBegins:
            jstart = iend + 1
            jend = kbegin
            if jstart < jend and checkMul(S, 'j', jstart, jend): return 'YES'
    return 'NO'

"""
pos = '1ijk'
for q1 in pos:
    for q2 in pos:
        print Q(q1)*Q(q2),
    print
"""

case = 1
inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0])
while case <= T:
    i = 2*case
    L, X = map(int, inp[i-1].strip().split())
    S = inp[i].strip()
    print "Case #%d: %s" % (case, solve(S, X))
    case += 1
