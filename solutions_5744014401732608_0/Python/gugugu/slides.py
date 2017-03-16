from __future__ import division

import os
#import sys
#from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

name = 'B-small-attempt0.in'

def _solve(b, m):
    nn = b * (b - 1) // 2

    def check(slide):
        pos = [0] * b
        pos[0] = 1
        for i in range(b):
            for j in range(i+1, b):
                if slide[i][j] == 1:
                    pos[j] += pos[i]
        #print(pos[b-1])
        return pos[b-1] == m


    for pos in range(2**nn):
        slide = [[0] * b for _ in range(b)]
        _pos = pos
        for i in range(b):
            for j in range(i+1, b):
                slide[i][j] = _pos % 2
                _pos = _pos // 2
        if check(slide):
            return slide
    return None

def solve(*args, **kwargs):
    res = _solve(*args, **kwargs)
    if res == None:
        return 'IMPOSSIBLE'
    return 'POSSIBLE\n' + '\n'.join([''.join(map(str, r)) for r in res])

#import sys
#print(solve(5, 6))
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









