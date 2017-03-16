# -*- coding: utf-8 -*-
"""
Problem B. 
uses python 3.3

@author: Eric Kuritzky
"""
from collections import *
import itertools as itool
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr
    
def errprt(*args, **kw):
    print(*args, file=stderr, **kw) 
    
def readcase(f):
    return readints(f)

def solvecase(a, b, k):
    cnt = 0
    n = max(len(binstr(z, 0)) for z in (a, b, k))
    aps, bps, kps = [prefixes(binstr(z, n)) for z in (a, b, k)]
#    print(aps, bps, kps)
    for ap in aps:
        for bp in bps:
            for kp in kps:
                cnt += common(ap, bp, kp, n)
#    assert cnt == brute(a, b, k)
    return str(cnt)

def common(a, b, k, n):
    a, b, k = [z + '?'*(n-len(z)) for z in (a, b, k)]
    c = ''.join('1' if ac==bc=='1' else '0' if ac=='0' or bc=='0' else '?'
                for ac, bc in zip(a, b))
#    print(c)
    if any((kc=='0' and cc=='1') or (kc=='1' and cc=='0') for cc, kc in zip(c, k)):
        return 0
    mask = ''.join(cc if cc!='?' else kc for cc, kc in zip(c, k))
    cnt = 1
    tbl0 = {'??' : 3, '0?' : 2, '?0' : 2, '01' : 1, '10' : 1,
            '00' : 1, '1?' : 1, '?1' : 1}
    for ac, bc, mc in zip(a, b, mask):
        if mc == '0':
            cnt *= tbl0[ac+bc]
        elif mc == '?':
            cnt *= (1 + (ac=='?')) * (2 if  bc=='?' else 1)
        else:
            assert a != '0' and b != '0'
 #   print(a, b, k, mask, cnt)
    return cnt

def brute(a, b, k):
    return sum(aa&bb<k for aa in range(a) for bb in range(b))

def binstr(x, n):
    a = bin(x)[2:]
    return '0'*(n-len(a)) + a

def prefixes(a):
    ans = []
    for n in range(len(a)):
        if a[n] == '1':
            ans.append(a[:n]+'0')
    return ans

def readints(f):
    return list(map(int, f.readline().strip().split(' ')))

def main():
    with open('B-large.in') as f, open('out', 'w') as out:
        cases = int(f.readline())
        for ncase in range(1, cases+1):
            case = readcase(f)
            soln = solvecase(*case)
            print('Case #%d: %s' % (ncase, soln))
            print('Case #%d: %s' % (ncase, soln), file=out)

from datetime import datetime

if True:
    start = datetime.now()
    print(str(start))
    main()
    stop = datetime.now()
    print(str(stop))
    print(str(stop-start))
