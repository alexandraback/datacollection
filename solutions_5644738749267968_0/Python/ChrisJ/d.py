#!/usr/bin/python

from __future__ import division

import sys

f = sys.stdin

# works on sorted lists
def optim(a, b):
    score = 0
    for wa in list(a):
        for wb in b:
            if wa>wb:
                a.remove(wa)
                b.remove(wb)
                score += 1
                break
    return score
    

T = int(f.readline())

for index in range(1, T+1):
    N = int( f.readline() )
    
    naomi = map(float, f.readline().split())
    ken = map(float, f.readline().split())

    naomi.sort()
    ken.sort()
    
    ken_score = optim(list(ken), list(naomi))
    
    naomi_deceit_score = optim(naomi, ken)

    print("Case #{}: {} {}".format(index, naomi_deceit_score, N - ken_score))
