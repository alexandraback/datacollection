#!/usr/bin/env python3

cases = int(input())



for T in range(1, cases+1):
    B, M = [int(x) for x in input().split()]

    max_ways = 2 ** (B-2)
    
    print("Case #{}: {}POSSIBLE".format(T, "IM" if M > max_ways else ""))

    if M <= max_ways:
        bits = (bin(M)[2:] + '0' if M < max_ways else '1' * (B-1))[::-1]
        while len(bits) < B:
            bits += "0"
        for b in range(B-1): 
            print("0" * (b+1) + "1" * (B-b-2) + bits[b])
        print("0" * B)

