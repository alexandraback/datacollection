#! /usr/bin/env python3

T = int(input())

for case_nr in range(1,T+1):
    K, C, S = [ int(i) for i in input().split() ]

    positions = []
    expand_factor = K**(C-1)
    for k in range(K):
        s = k * expand_factor 
        positions.append(s)
    
    result = ' '.join([ str(p+1) for p in positions ])
    print("Case #{}: {}".format(case_nr, result))

