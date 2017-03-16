# -*- coding: utf-8 -*-

import sys

def flip_sign(c):
    if c=='-':
        return '+'
    else:
        return '-'

def flip(s, pos):
    return "".join(map(flip_sign, reversed(s[:pos])))+s[pos:]

    
def next_step(s, step=0):
    pos = s.find('-')
    if pos == -1:
        return step
    if pos == 0:
        pos = s.rfind('-')+1
    s = flip(s, pos)
    return next_step(s, step+1)

filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        s = f.readline().strip()
        res = next_step(s)
        print 'Case #{}: {}'.format(i+1,res)
        
