from __future__ import division

import os
import sys
from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

name = 'A-large.in'

def _solve(inp):
    if inp == '':
        return ''
    mx = max(inp)
    first = inp.index(mx)
    last = len(inp) - 1 - (inp[::-1]).index(mx)
    mxs = ''
    rest = ''
    for l in inp[first:(last+1)]:
        if l == mx:
            mxs += l
        else:
            rest += l
    return mxs + _solve(inp[:first]) + rest + inp[(last+1):]

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
    inp = inp_file.readline().strip()
    res = solve(inp)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()









