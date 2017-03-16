from __future__ import division

import os
import sys
name = 'A-small-attempt0'


def _solve(goal):
    bst = {}
    q = []
    bst[1] = 1
    q.append(1)
    def update(k, v):
        if k not in bst:
            bst[k] = v
            q.append(k) 

    def rev(s):
        return int(str(s)[::-1])

    while q:
        f = q.pop(0)
        v = bst[f]
        update(f+1, v+1)
        update(rev(f), v+1)
        if goal in bst:
            return bst[goal]


def format(out):
    return out

def solve(*args, **kwargs):
    return format(_solve(*args, **kwargs))

#print(solve(1),1)
#print(solve(19),19)
#print(solve(23),15)
#print(solve(987654),'?')
#print(solve(123456),'?')
#sys.exit(0)

os.system('cp /home/mama/Downloads/%s.in .'%name)
os.system('rm /home/mama/Downloads/%s*.in'%name)
lines = open('%s.in'%name).readlines()
output = open('%s.out'%name, 'w')
cases = int(lines[0])
curline = 1
for caseno in range(cases):
    inp = int(lines[curline].strip())
    curline += 1
    output.write('Case #%d: %s\n'%((caseno+1), str(solve(inp))))
    output.flush()
output.close()
    








