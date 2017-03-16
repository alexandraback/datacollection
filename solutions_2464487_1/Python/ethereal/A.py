#!/usr/bin/env python3

import math

def area(r): return r*r

def rarea(r): return area(r+1) - area(r)

def cost(r, count):
    if(count <= 2): return rarea(r)
    if(count % 2 == 1): return cost(r, count-1)
    return cost(r, count-2) + 4

def cost_iterative(r, count):
    cost = rarea(r)
    while count > 0:
        if(count % 2 == 1):
            count -= 1
        else:
            count -= 2
            cost += 4*math.pi
    return cost

def cost_closed(r, count):
    if(count <= 0): return 0
    return rarea(r) + (count-1)*4*math.pi

def sum_closed(r, k):
    return k*rarea(r) + ((k*(k-1))//2)*4

def bsearch(r, t, c, off):
    if(off < 1):
        return math.floor(c)

    ca = sum_closed(r, c)

    if(ca > t):
        return bsearch(r, t, c-off//2, off//2)
    if(ca < t):
        return bsearch(r, t, c+off//2, off//2)
    return c

count = int(input())
for i in range(count):
    l = input().split()
    r = int(l[0])
    t = int(l[1])
    c = bsearch(r, t, 2**33, 2**33)

    while(sum_closed(r, c+1) <= t): c += 1
    while(sum_closed(r, c) > t): c -= 1
    #print(c, sum_closed(r, c), sum_closed(r, c+1))
    print("Case #" + str(i+1) + ": " + str(c))

#print(bsearch(3, 40, 2**33, 2**33))
#
#print(cost(3, 3), cost(3, 4))
#print(cost_iterative(3, 3), cost_iterative(3, 4))
#print(cost_closed(3, 3), cost_closed(3, 4))

#print(cost_closed(0, 1), cost_closed(0, 2), cost_closed(0, 3), cost_closed(0, 4))
#print(sum_closed(0, 1), sum_closed(0, 2), sum_closed(0, 3), sum_closed(0, 4))
#print(cost(3, 1), cost(3, 2), cost(3, 3), cost(3, 4))
#print(bsearch(1, 1000000000000000000, 2**33, 2**33))
