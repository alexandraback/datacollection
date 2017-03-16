#/usr/bin/env python

import sys, os
from math import ceil

# the first line is the total number of cases
cases_total = int(sys.stdin.readline().strip())

case = 0                                # id of the case
while case < cases_total:
    case += 1                           # iterate case id

    # do your input here
    line = sys.stdin.readline()
    [ C, D, V ] = [ int(x) for x in line.strip().split() ]
    coins = [ int(x) for x in sys.stdin.readline().strip().split() ]

    # build a list of possible payables
    possibles = []
    # using a binary number
    n = 2**len(coins)
    while n>0:
        # the binary mask is
        bin_mask = bin(n)[2:]
        if len(bin_mask)<D:
            bin_mask = "0"*(D-len(bin_mask))+bin_mask
        denom = 0
        for i in range(D):
            denom += coins[i]*int(bin_mask[i])
        possibles.extend([denom])
        n = n - 1

    possibles.sort()

    impossibles = []
    for i in range(1,V+1):
        if not i in possibles:
            impossibles.extend([i])

    # the smallest impossible should be added as the extra coin
    n_extra = 0
    while len(impossibles)>0:
        n_extra += 1
        new_coin = impossibles[0]
        new_possibles = []
        new_possibles.extend([new_coin])
        for i in possibles:
            new_possibles.extend([i+new_coin])

        possibles = possibles + new_possibles
        possibles = list(set(possibles))
        possibles.sort()

        new_impossibles = []
        for i in impossibles:
            if not(i in possibles):
                new_impossibles.extend([i])
        impossibles = new_impossibles

    # set your output here
    out = str(n_extra)

    print "Case #"+str(case)+": "+out   # the output format is 'Case #${case}: ${output}'
