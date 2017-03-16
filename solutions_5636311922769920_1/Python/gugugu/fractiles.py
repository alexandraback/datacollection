from __future__ import division

import os
import sys
from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

#name = 'fractile_micro.in'
name = 'D-large.in'

def _solve(k, c, s):
    res = set()
    seen = [False for _ in range(k)]
    def see():
        for i in range(k):
            if not seen[i]:
                seen[i] = True
                return i
        return None

    while not all(seen):
        tile = 0
        for i in range(c):
            _tile = see()
            if _tile == None:
                break
            tile *= k
            tile += _tile
        res.add(tile + 1)

    if len(res) > s:
        return 'IMPOSSIBLE'
    else:
        return ' '.join(map(str, sorted(res)))

def solve(*args, **kwargs):
    res = _solve(*args, **kwargs)
    return res

#print(solve(10, 3, 4))
#sys.exit()

inp_path = '/home/mama/Downloads/%s'%name
if os.path.isfile(inp_path):
    os.system('mv %s .' % inp_path)
inp_file = open(name)
out_file = open('%s.out'%name, 'w')
cases = int(inp_file.readline())
for caseno in range(cases):
    inp = tuple(int(x) for x in inp_file.readline().split())
    res = solve(*inp)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()









