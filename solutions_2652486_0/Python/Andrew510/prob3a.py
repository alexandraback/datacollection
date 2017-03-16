#!/usr/bin/python

import sys

infile = sys.stdin

primes = [ 2, 3, 5, 7 ]

T = int(infile.readline())
R, N, M, K = map(int, infile.readline().split())
#assert N == 3
#assert M == 5
#assert K == 7

print 'Case #1:'
for r in range(R):
    prod = map(int, infile.readline().split())
    
    seen = [0, 0, 0]
    need = [0, 0, 0]

    for p in prod:
        nn = [0, 0, 0]
        while (p%2) == 0:
            seen[0] += 1
            nn[0] += 1
            p /= 2
        
        while (p%3) == 0:
            seen[1] += 1
            nn[1] += 1
            p /= 3

        while (p%5) == 0:
            seen[2] += 1
            nn[2] += 1
            p /= 5

        assert p == 1

        if nn[0] > need[0]: need[0] = nn[0]
        if nn[1] > need[1]: need[1] = nn[1]
        if nn[2] > need[2]: need[2] = nn[2]

    cards = ''
    n = 0
    while need[1] > 0:
        cards += '3'
        n += 1
        need[1] -= 1
        seen[1] -= K/2

    while need[2] > 0:
        cards += '5'
        n += 1
        need[2] -= 1
        seen[1] -= K/2
    
    while need[0] > N-n:
        cards += '4'
        n += 1
        need[0] -= 2
        seen[0] -= K/2

    prob2 = seen[0]
    prob4 = seen[0] / 2
    prob3 = seen[1]
    prob5 = seen[2]

    while n < N:
        mp = max((prob2, prob3, prob4, prob5))
        if mp == prob2:
            cards += '2'
            n += 1
            prob2 -= K/2
            prob4 -= K
        elif mp == prob3:
            cards += '3'
            n += 1
            prob3 -= K/2
        elif mp == prob4:
            cards += '4'
            n += 1
            prob2 -= K/2
            prob4 -= K
        elif mp == prob5:
            cards += '5'
            n += 1
            prob5 -= K/2

    print cards
