#!/usr/bin/env python

from collections import defaultdict

TEST="""4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER"""
#raw_input = iter(TEST.splitlines()).next

ALL = "ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE"
NUMS = ALL.split()

# Zero, siX, tWo, foUr and eiGht are easy... as unique numbers
# Then..
# Five, tHree, SeVen
# Leaving...
# one and nIne
def solve(S):
    totals = {}
    ctr = defaultdict(int)
    for c in S: ctr[c] += 1

    totals['0'] = ctr['Z']
    totals['6'] = ctr['X']
    totals['2'] = ctr['W']
    totals['4'] = ctr['U']
    totals['8'] = ctr['G']

    ctr['F'] -= totals['4']
    ctr['H'] -= totals['8']
    ctr['S'] -= totals['6']

    totals['5'] = ctr['F']
    totals['3'] = ctr['H']
    totals['7'] = ctr['S']

    ctr['I'] -= totals['6']
    ctr['I'] -= totals['5']
    ctr['I'] -= totals['8']

    ctr['O'] -= totals['0']
    ctr['O'] -= totals['2']
    ctr['O'] -= totals['4']

    totals['9'] = ctr['I']
    totals['1'] = ctr['O']

    R = ""
    for k in sorted(totals.keys()):
        if totals[k]:
            R += (k*totals[k])
    return R


T = int(raw_input())
for case in range(1,T+1):
    S = raw_input().strip()
    print("Case #%s: %s" % (case, solve(S)))
