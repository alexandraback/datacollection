from __future__ import division

import os
#import sys
#from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

name = 'B-large.in'
#name = 'micro.in'

def _solve(b,m):

    def check(slide):
        pos = [0] * b
        pos[0] = 1
        for i in range(b):
            for j in range(i+1, b):
                if slide[i][j] == 1:
                    pos[j] += pos[i]
        return pos[b-1] == m

    slide = [[0] * b for _ in range(b)]
    k = b - 2
    pos = 1
    while True:
        if k < 0:
            assert(2**(b-2) < m)
            return
        if pos >= m:
            break
        for i in range(k+1, b):
            slide[k][i] = 1
        k -= 1
        pos *= 2
    mm = m
    for j in range(k+1, b-1):
        pos = pos // 2
        if mm >= pos:
            mm -= pos
            slide[k][j] = 1
    if mm == 1:
        slide[k][b-1] = 1
        mm = 0
    assert(mm == 0)
    if k > 0:
        slide[0][k] = 1
    assert(check(slide))
    return slide

def solve(*args, **kwargs):
    res = _solve(*args, **kwargs)
    if res == None:
        return 'IMPOSSIBLE'
    return 'POSSIBLE\n' + '\n'.join([''.join(map(str, r)) for r in res])

#import sys
#print(solve(50, 2**13+123))
#sys.exit()

inp_path = '/home/mama/Downloads/%s'%name
if os.path.isfile(inp_path):
    os.system('mv %s .' % inp_path)
inp_file = open(name)
out_file = open('%s.out'%name, 'w')
cases = int(inp_file.readline())
for caseno in range(cases):
    (b, m) = tuple(map(int, inp_file.readline().split()))
    res = solve(b, m)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()









