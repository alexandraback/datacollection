# -*- coding: utf-8 -*-
"""
Created on Sat Apr 30 20:06:59 2016

@author: Eidan Cohen
"""

from itertools import combinations

def relatively_fake(pair, lst):
    w1, w2 = pair
    mark1, mark2 = False, False
    for z1, z2 in lst:
        if (w1,w2) == (z1,z2):
            continue
        if w1 == z1:
            mark1 = True
        if w2 == z2:
            mark2 = True
    return mark1 and mark2

def solve(lst):
    """
    r = 0
    for w1, w2 in lst:
        mark1, mark2 = False, False
        for z1, z2 in lst:
            if (w1,w2) == (z1,z2):
                continue
            if w1 == z1:
                mark1 = True
            if w2 == z2:
                mark2 = True
        if mark1 and mark2:
            r += 1
    return r
    """
    st = set(lst)
    for r in range(len(lst), -1, -1):
        for fakes in combinations(st, r):
            reals = st - set(fakes)
            if all(relatively_fake(pair, reals) for pair in fakes):
                return r
    assert False
        
    
def main():
    t = int(input())
    for i in range(1,t+1):
        n = int(input())
        lst = []
        for j in range(n):
            lst.append(tuple(input().lstrip().split(" ")))
        print('Case #{0}: {1}'.format(i, solve(lst)))

if __name__ == '__main__':
    main()

