#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

def case():
    stack = line()
    cur = '+'
    res = 0
    for c in reversed(stack):
        if c != cur:
            res += 1
            cur = c
    return res

if __name__ == '__main__':
    main()
