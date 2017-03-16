#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

def case():
    n, = ints()
    return solve(n)

def solve(n):
    if not n: return 'INSOMNIA'
    nums = set()
    i = 1
    while True:
        nums.update(set(str(n*i)))
        if len(nums) == 10: return n*i
        i += 1

if __name__ == '__main__':
    main()
