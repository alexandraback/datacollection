from __future__ import division

import os
import sys
from math import log, floor, ceil, sqrt, pi
#from random import randint, choice, shuffle
#from collections import defaultdict
#from heapq import heappush, heappop, heapify
#inf = 10**20

name = 'C-small-attempt1.in'


def _solve(perm):
    perm = [elem - 1 for elem in perm]
    proc = {}
    n = len(perm)
    for e in range(len(perm)):
        if e in proc:
            continue

        seen = set()
        c = e
        ll = 0
        while True:
            if c in seen:
                break
            if c in proc and proc[c][0] == 'e':
                proc[e] = (proc[c][0], proc[c][1] + ll, proc[c][2])
            seen.add(c)
            c = perm[c]
            ll += 1
        if e in proc:
            continue
        seen = set()
        mn = None
        while True:
            if mn == None or c < mn:
                mn = c
            if c in seen:
                break
            seen.add(c)
            c = perm[c]
        seen = set()
        while True:
            proc[c] = ('c', mn)
            if c in seen:
                break
            seen.add(c)
            c = perm[c]

        # find which connects
        c = e
        l = 0
        while True:
            if c in proc:
                nap = c
                break
            l += 1
            c = perm[c]
        c = e
        while True:
            if c in proc:
                break
            proc[c] = ('e', l, nap)
            l -= 1

    cycles = {}
    for p, v in proc.items():
        if v[0] == 'c':
            if v[1] not in cycles:
                cycles[v[1]] = 1
            else:
                cycles[v[1]] += 1


    mx = max(cycles.values())

    print(proc)
    #print(cycles)
    for i in range(n):
        for j in range(i + 1, n):
            if proc[i][0] == 'e':
                nap = proc[i][2]
                print(i, nap)
                assert(proc[nap][0] == 'c')
                if cycles[proc[nap][1]] > 2:
                    continue
                mx = max(mx, proc[i][1] + 2)
                if proc[j][0] == 'e':
                    nap2 = proc[j][2]
                    assert(proc[nap2][0] == 'c')
                    if proc[nap] != proc[nap2]:
                        continue
                    if nap == nap2:
                        continue
                    mx = max(mx, proc[i][1] + proc[j][1] + 2)

    return mx


def solve(*args, **kwargs):
    res = _solve(*args, **kwargs)
    return res

#print(solve((2, 3, 1, 10, 3, 5, 6, 7, 8, 9)))
#sys.exit()

#print(_solve((7, 8, 10, 10, 9, 2, 9, 6, 3, 3)))
#print(_solve((3, 3, 4, 3)))

inp_path = '/home/mama/Downloads/%s'%name
if os.path.isfile(inp_path):
    os.system('mv %s .' % inp_path)
inp_file = open(name)
out_file = open('%s.out'%name, 'w')
cases = int(inp_file.readline())
for caseno in range(cases):
    (n,) = tuple(map(int, inp_file.readline().split()))
    inp = tuple(int(x) for x in inp_file.readline().split())
    res = solve(inp)
    print(caseno, res)
    print('---')
    out_file.write('Case #%d: %s\n'%((caseno+1), res))
    out_file.flush()
out_file.close()









