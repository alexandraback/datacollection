from __future__ import division

import os
import sys
from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

name = 'B-small-attempt0.in'

def _solve(rows):
    seen = {}
    for row in rows:
        for elem in row:
            if elem not in seen:
                seen[elem] = 1
            else:
                seen[elem] += 1
    res = []
    for elem, cnt in seen.items():
        if cnt % 2 == 1:
            res.append(elem)
    res = sorted(res)
    return ' '.join(map(str, res))

def solve(*args, **kwargs):
    res = _solve(*args, **kwargs)
    return res

inp_path = '/home/mama/Downloads/%s'%name
if os.path.isfile(inp_path):
    os.system('mv %s .' % inp_path)
inp_file = open(name)
out_file = open('%s.out'%name, 'w')
cases = int(inp_file.readline())
for caseno in range(cases):
    (n,) = tuple(map(int, inp_file.readline().split()))
    rows = []
    for i in range(2 * n - 1):
        inp = tuple(int(x) for x in inp_file.readline().split())
        rows.append(inp)
    res = solve(rows)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()









