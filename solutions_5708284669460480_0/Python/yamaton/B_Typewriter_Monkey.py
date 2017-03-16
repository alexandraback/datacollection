#!/usr/bin/env python3
"""
Google Code Jam
2015 Round 1C

Problem B. Typewriter Monkey

@author: yamaton
@date: 2015-05-10
"""

import itertools
import functools
import operator
import collections
import math
import sys


def match_count(target, s):
    num_target = len(target)
    k = len(s)
    out = sum(1 for i in range(k - num_target + 1) if s[i:i+num_target] == target)
    return out


def bruteforce(monkey, target, K, L, S):
    monkey_cnt = collections.Counter(monkey)
    target_cnt = collections.Counter(target)
    if set(target_cnt.keys()) - set(monkey_cnt.keys()):
        return 0.0

    monkey_types = map(lambda s: ''.join(s), itertools.product(monkey, repeat=S))
    statistics = [match_count(target, m) for m in monkey_types]
    expected = sum(statistics) / len(statistics)
    return max(statistics) - expected



if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #%d: " % (i + 1), end='')
        K, L, S = [int(s) for s in input().strip().split()]
        monkey = input().strip()   # only uppercase letters
        target = input().strip()
        result = bruteforce(monkey, target, K, L, S)
        print(result)
        
        print('\n--------- case #%d -------' % (i + 1), file=sys.stderr)
        print('monkey =', monkey, file=sys.stderr)
        print('target =', target, file=sys.stderr)
        print('K, L, S =', (K, L, S), file=sys.stderr)
        print('result =', result, file=sys.stderr)