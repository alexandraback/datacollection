#!/usr/bin/env python2
# -*- coding: utf-8 -*-

from itertools import product

nums = map(chr, xrange(ord('0'), ord('9') + 1))

def all_poss(s):
    c = s.count('?')
    for ks in product(nums, repeat=c):
        res = ''
        j = 0
        for (i, ch) in enumerate(s):
            if ch == '?':
                res += ks[j]
                j += 1
            else:
                res += ch
        yield res

def case(t):
    res = ''
    a, b = raw_input().split()
    d, pa, pb = min((abs(int(pa)-int(pb)), pa, pb) for (pa, pb) in product(all_poss(a), all_poss(b)))
    print('Case #{}: {} {}'.format(t, pa, pb))

if __name__ == "__main__":
    map(case, xrange(1, int(raw_input())+1))
