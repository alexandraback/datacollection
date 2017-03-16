#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

def case():
    K, C, S = ints()
    if S*C < K:
        return 'IMPOSSIBLE'
    result = [0] * S
    rp = cp = 0
    for i in range(K):
        result[rp] += i * (K**cp)
        cp += 1
        if cp == C:
            cp = 0
            rp += 1
    return ' '.join(str(i+1) for i in sorted(set(result)))

if __name__ == '__main__':
    main()
