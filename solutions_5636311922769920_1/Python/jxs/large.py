#! /usr/bin/env python3

T = int(input())

for case_nr in range(1,T+1):
    K, C, S = [ int(i) for i in input().split() ]

    positions = []
    s, c = 0, 1
    for k in range(1,K):
        # if possible expand and add tile to check
        if c < C:
            s = s * K + k
            c += 1
        else:
            positions.append(s)
            c, s = 1, k
    
    positions.append(s)

    if len(positions) <= S:
        result = ' '.join([ str(p+1) for p in positions ])
        print("Case #{}: {}".format(case_nr, result))
    else:
        print("Case #{}: IMPOSSIBLE".format(case_nr))

