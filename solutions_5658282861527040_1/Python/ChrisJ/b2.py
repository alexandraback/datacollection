#!/usr/bin/python

import sys
import math

f = sys.stdin


T = int(f.readline())

def bits(x):
    return int(math.ceil(math.log(x) / math.log(2)))

def calc(A, B, K):
    #dbg = "calc({}, {}, {})".format(A, B, K)
    #print(dbg)

    [A, B] = [min(A, B), max(A, B)]

    # number of bits
    [bitsA, bitsB, bitsK] = map(bits, [A, B, K])

    #print(A, bitsA, B, bitsB, K, bitsK)

    if K >= A:
        res = A*B
    else: #if bitsB > bitsK:
        res = calc(A, 2**(bitsB-1), K)   # with heading 0
        if bitsB > bitsA:
            res += calc(A, B - 2**(bitsB-1), K)        # also with heading 1
        else:  # bitsB = bitsA
            res += calc(2**(bitsA-1), B-2**(bitsB-1), K)
            
            if bitsK == bitsB:
                res += calc(A-2**(bitsA-1), B-2**(bitsB-1), K-2**(bitsK-1))
            
    #print("<-- {} = {}".format(dbg, res))

    return res

for index in range(1, T+1):
    [A, B, K] = map(int, f.readline().split())
    
    print("Case #{}: {}".format(index, calc(A, B, K)))

    
    #2n1 = 2**(n-1)

    #count = min(A, 2n1) * B + min(B, 2n1) * A
    
    #if A > 2n_1:
        