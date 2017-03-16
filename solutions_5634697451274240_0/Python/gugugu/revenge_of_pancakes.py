from __future__ import division

import os
import sys
from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

name = 'B-small-attempt0.in'

def _solve(s):
    res = {
        '++': 0,
        '+-': 0,
        '-+': -1,
        '--': -1,
    }[s[0]+s[len(s) - 1]]
    s = s + '+'
    last = '+'
    for pancake in s:
        if pancake != last:
            last = pancake
            res += 1
    return res

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
    s = inp_file.readline().strip()
    res = solve(s)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()









