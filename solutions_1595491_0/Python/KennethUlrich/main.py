from collections import defaultdict
import os
import sys

def rank(p, total):
    score = total - (p * 3 - 2)
    if score >= 0:
        return 1
    if p >= 2 and score >= -2:
        return 0
    return -1

sys.stdin.readline()

for tc, line in enumerate(sys.stdin):
    v = [int(n) for n in line.strip().split()]
    n, s, p = v[0:3]
    googlers = v[3:]
    ranks = sorted([rank(p, g) for g in googlers], reverse=True)
    result = 0
    for r in ranks:
        if r > 0:
            result += 1
        elif r == 0 and s > 0:
            result += 1
            s -= 1
            if s == 0:
                break
    print "Case #%d: %d" % (tc + 1, result)
            
    
    
    