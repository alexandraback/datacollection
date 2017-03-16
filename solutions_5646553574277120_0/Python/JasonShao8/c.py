from copy import deepcopy
from math import log

def digi(a):
    count = 0
    while a:
        a = a/2
        count += 1
    return count

t = input()
for tests in range(1, t + 1):
    c,d,v = map(int, raw_input().split())
    l = map(int, raw_input().split())
    hacks = set()
    for i in l:
        hacks2 = deepcopy(hacks)
        for j in hacks:
            hacks2.add(j + i)
        hacks2.add(i)
        hacks = hacks2
    count = 0
    for i in range(1, v+1):
        if i not in hacks:
            count += 1
            hacks.add(i)
            for j in deepcopy(hacks):
                hacks.add(j + i)

    print "Case #" + str(tests) + ": " + str(count)


    
