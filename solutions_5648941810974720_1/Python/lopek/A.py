#!/usr/bin/python
from pprint import pprint

def solve(s):
    cnt = dict()
    for x in xrange(ord('A'), ord('Z') + 1):
        cnt[chr(x)] = 0
    for x in s:
        cnt[x] += 1
   
    res = dict([(x, 0) for x in range(10)])

    res[0] = cnt['Z']
    for c in "EROZ":
        cnt[c] -= cnt['Z']

    res[6] = cnt['X']
    for c in "SIX":
        cnt[c] -= cnt['X']

    res[8] = cnt['G']
    for c in "EIHTG":
        cnt[c] -= cnt['G']

    res[3] = cnt['H']
    for c in "TREEH":
        cnt[c] -= cnt['H']

    res[7] = cnt['S']
    for c in "EVENS":
        cnt[c] -= cnt['S']
    
    res[5] = cnt['V']
    for c in "FIEV":
        cnt[c] -= cnt['V']

    res[4] = cnt['F']
    for c in "OURF":
        cnt[c] -= cnt['F']
    
    res[2] += cnt['W']
    for c in "TOW":
        cnt[c] -= cnt['W']

    res[1] = cnt['O']
    res[9] = cnt['I']

    ress = ''
    for x in xrange(10):
        ress += str(x) * res[x]
    return ress

T = int(raw_input())
for t in xrange(1, T + 1):
    s = raw_input()
    print("Case #%d: %s" % (t, solve(s)))
