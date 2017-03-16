#!/usr/bin/python

def generate(ar, e, r, cur_e, gain):
    if ar == []:
        return gain
    maxgain = 0
    for i in range(cur_e+1):
        maxgain = max(maxgain, generate(ar[1:], e, r, min(e, cur_e - i +r), gain + (i*ar[0])))
    return maxgain

cases = int(raw_input())

for casenum in range(1, cases + 1):
    line = raw_input()
    e = int(line.split()[0])
    r = int(line.split()[1])
    n = int(line.split()[2])
    line = raw_input()
    ar = [int(i) for i in line.split()]
    print "Case #{}: {}".format(casenum, generate(ar, e, r, e, 0))
