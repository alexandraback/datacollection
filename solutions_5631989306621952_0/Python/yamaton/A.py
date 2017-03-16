"""
Google Code Jam
2016 Round 1A

Problem A.
    :author: yamaton
    :date: 2016-04-15
"""

import itertools as it
import functools
import operator
import collections
import math
import sys

sys.setrecursionlimit(3000)

def solve(s):
    if len(s) <= 1:
        return s
    s = list(s)
    max_letter = sorted(s)[-1]
    max_pos = [i for (i, c) in enumerate(s) if c == max_letter][-1]
    right = s[max_pos+1:]
    left = s[:max_pos]
    pp('left', left)
    pp('right', right)
    return [max_letter] + solve(left) + right


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        s = input().strip()
        result = ''.join(solve(s))
        pp()
        pp('s =', s)
        pp('result =', result)
        print(result)


if __name__ == '__main__':
    main()
