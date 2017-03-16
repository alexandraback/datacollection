#!/usr/bin/python

def getmaxrings(r, paint):
    tot = (r+1)**2 - r**2
    add = 1
    while tot <= paint:
        add += 2
        tot = tot + (r+add)**2 - (r+add-1)**2

    return add/2

cases = int(raw_input())

for casenum in range(1, cases + 1):
    line = raw_input()
    r = int(line.split()[0])
    t = int(line.split()[1])
    print "Case #{}: {}".format(casenum, getmaxrings(r, t))
