#! /usr/bin/env python

T = int(input())

for t in range(1, T+1):
    x, r, c = [int(n) for n in input().split()]
    
    if x >= 7 or r*c % x != 0:
        print("Case #{}: {}".format(t, "RICHARD"))
    elif x < 3:
        print("Case #{}: {}".format(t, "GABRIEL"))
    elif x == 3:
        if min(r, c) >= 2 and max(r, c) >= 3:
            print("Case #{}: {}".format(t, "GABRIEL"))
        else:
            print("Case #{}: {}".format(t, "RICHARD"))
    elif x == 4:
        if min(r, c) >= 3 and max(r, c) >= 4:
            print("Case #{}: {}".format(t, "GABRIEL"))
        else:
            print("Case #{}: {}".format(t, "RICHARD"))
    else:
        if min(r, c) >= 4 and max(r, c) >= x:
            print("Case #{}: {}".format(t, "GABRIEL"))
        else:
            print("Case #{}: {}".format(t, "RICHARD"))

