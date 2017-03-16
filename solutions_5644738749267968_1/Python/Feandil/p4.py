#!/usr/env/python

import bisect
from sys import stdin

def read_weigths():
    data = [float(i) for i in stdin.readline().strip().split()]
    data.sort()
    return data

def solv_war(naomi, ken):
    n = 0
    while len(naomi) > 0:
        smaller = naomi.pop(0)
        index = bisect.bisect(ken, smaller)
        if index == 0:
            ken.pop(0)
        elif index == len(ken):
            n += 1
            ken.pop(0)
        else:
            ken.pop(index)
    return n

def solv_deceive_war(naomi, ken):
    n = 0
    while len(naomi) > 0:
        bigger = naomi[-1]
        index = bisect.bisect(ken, bigger)
        if index == 0:
            ken.pop(0)
            naomi.pop()
        elif index == len(ken):
            n += 1
            k = ken.pop(0)
            index = bisect.bisect(naomi, k)
            naomi.pop(index)
        else:
            naomi.pop(0)
            ken.pop(index)
    return n

def solve_probs():
    stdin.readline()
    naomi = read_weigths()
    ken = read_weigths()
    war = solv_war(list(naomi), list(ken))
    deceive_war = solv_deceive_war(list(naomi), list(ken))
    return '{} {}'.format(str(deceive_war), str(war))

nb = int(stdin.readline().strip())
for i in range(1, nb + 1):
    print('Case #{}: {}'.format(i, solve_probs()))
