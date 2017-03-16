#!/usr/bin/env python

import sys

T = int(sys.stdin.readline())

for t in range (1, T+1):
    n = int(sys.stdin.readline())
    naomi = [float(x) for x in sys.stdin.readline().split(" ")]
    ken = [float(x) for x in sys.stdin.readline().split(" ")]
    naomi.sort(reverse=True)
    ken.sort(reverse=True)
    ken_highest = 0
    naomi_point = 0
    for i in range(n):
        if (naomi[i] > ken[ken_highest]):
            naomi_point += 1
        else:
            ken_highest += 1
    
    cheat_naomi_point = 0
    naomi_highest = 0
    for i in range(n):
        if (naomi[naomi_highest] > ken[i]):
            cheat_naomi_point += 1
            naomi_highest += 1
            
    print("Case #{case}: {cheat} {honest}".format(case = t,
                                                  cheat = cheat_naomi_point, 
                                                  honest = naomi_point))
