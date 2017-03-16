#!/usr/bin/env python3
"""
Google Code Jam
2015 Round 1C

Problem A. Brattleship

@author: yamaton
@date: 2015-05-10
"""

import itertools
import functools
import operator
import collections
import math
import sys


# w <= s < 2 * w
def remaining_count(s, w):
    if s == w:
        return w
    else:
        return w + 1



# when R = 1
def solve(R, C, W):
    if W == 1:
        return R * C
    initial = C // W - 1
    return initial + remaining_count(W + C % W, W)


if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #%d: " % (i + 1), end='')
        R, C, W = [int(s) for s in input().strip().split()]
        result = solve(R, C, W)
        print(result)
        
        print('\n--------- case #%d -------' % (i + 1), file=sys.stderr)
        print('R C W =', (R, C, W), file=sys.stderr)
        print('result =', result, file=sys.stderr)