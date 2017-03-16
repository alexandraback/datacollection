#!/usr/bin/env python3

import sys
from decimal import Decimal
from heapq import *
from collections import deque
from copy import copy

def deceitful(naomi, ken):
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

if __name__ == '__main__':
    ncases = int(sys.stdin.readline())
    for i in range(1, ncases + 1):
        n = int(sys.stdin.readline())
        naomi = [Decimal(x) for x in sys.stdin.readline().split()]
        ken = [Decimal(x) for x in sys.stdin.readline().split()]
        naomi.sort()
        ken.sort()
        print("Case #{}: {} {}".format(i, deceitful(naomi, ken), war(naomi, ken)))