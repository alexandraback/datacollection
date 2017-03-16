#!/usr/bin/env python3

import sys
rl = lambda: sys.stdin.readline()
T = int(rl())

def solve(casei):
    line = rl().split()
    smax = int(line[0])
    mystr = str(line[1])
    friends = 0
    standed = 0
    for shyness in range(0, smax+1):
        x = int(mystr[shyness])
        if x == 0:
            continue
        if standed < shyness:
            new_friends = shyness - standed
            friends += new_friends
            standed += new_friends
        standed += x
    print("Case #{}: {}".format(casei, friends))

for i in range(1, T+1):
    solve(i)
