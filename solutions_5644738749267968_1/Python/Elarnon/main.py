#!/usr/bin/env python3

import sys
from decimal import Decimal
from heapq import *
from collections import deque
from copy import copy
from random import randint, shuffle

def deceitful(naomi, ken):
    naomi = copy(naomi)
    ken = copy(ken)
    # Use the lightest from naomi to discard the heaviest from ken
    n = len(naomi)
    naomi.reverse()
    naomi = deque(naomi, n)
    ken = deque(ken, n)
    res = 0
    while n > 0:
        while n > 0 and ken[n-1] > naomi[0]:
            naomi.pop()
            ken.pop()
            n -= 1
        while n > 0 and naomi[0] > ken[n-1]:
            res += 1
            naomi.popleft()
            ken.pop()
            n -= 1
    return res

# Arguments are sorted
def war(naomi, ken):
    naomi = copy(naomi)
    ken = copy(ken)
    res = 0
    for n in naomi:
        kchoice = None
        smallest = None
        k = heappop(ken)
        m = k
        ks = set()
        while k < n and len(ken) > 0:
            ks.add(k)
            k = heappop(ken)
            if k < m:
                m = k
        if k < n:
            # Push back and keep the min
            ks.add(k)
            for k in ks:
                if k != m:
                    heappush(ken, k)
            res += 1
        else:
            for k in ks:
                heappush(ken, k)
    return res

def gen_n_ints(nb, f, l):
    gens = set()
    while len(gens) < nb:
        gens.add(randint(f, l))
    res = list(gens)
    shuffle(res)
    return res

def fuzzy(k):
    for i in range(1, k):
        n = 1000 # randint(1, 1000)
        vals = gen_n_ints(2 * n, 1, 100000)
        naomi = [0] * n
        ken = [0] * n
        for j in range(0, int(len(vals) / 2)):
            naomi[j] = vals[2 * j]
            ken[j] = vals[2 * j + 1]
        naomi.sort()
        ken.sort()
        deceitful(naomi, ken)
        war(naomi, ken)

if __name__ == '__main__':
    ncases = int(sys.stdin.readline())
    for i in range(1, ncases + 1):
        n = int(sys.stdin.readline())
        naomi = [int(Decimal(x) * 1000000) for x in sys.stdin.readline().split()]
        ken = [int(Decimal(x) * 1000000) for x in sys.stdin.readline().split()]
        naomi.sort()
        ken.sort()
        print("Case #{}: {} {}".format(i, deceitful(naomi, ken), war(naomi, ken)))