#!/usr/bin/env python3
import sys
import math
import decimal

class MultiLevelBreak(Exception):pass

def fewest_levels(ab):
    onestar = [set([]) for i in range(0,2002)]
    twostar = [set([]) for i in range(0,2002)]
    both = [set([]) for i in range(0,2002)]
    left = len(ab)*2
    for i, (a,b) in enumerate(ab):
        onestar[a].add(i)
        twostar[b].add(i)
        both[max((a,b))].add(i)
    count = 0
    stars = 0
    while left > 0:
        try:
            i = stars
            while i >= 0:
                if len(both[i]) > 0:
                    level = both[i].pop()
                    for i in range(0, 2002):
                        onestar[i].discard(level)
                        twostar[i].discard(level)
                    stars += 2
                    count += 1
                    left -= 2
                    raise MultiLevelBreak()
                i -= 1
            i = stars
            while i >= 0:
                if len(twostar[i]) > 0:
                    level = twostar[i].pop()
                    for i in range(0,2002):
                        both[i].discard(level)
                        onestar[i].discard(level)
                    stars += 1
                    count += 1
                    left -= 1
                    raise MultiLevelBreak()
                if len(onestar[i]) > 0:
                    level = onestar[i].pop()
                    for i in range(0,2002):
                        twostar[i].discard(level)
                        both[i].discard(level)
                    stars += 1
                    count += 1
                    left -= 1
                    raise MultiLevelBreak()
                i -= 1
            return "Too Bad"
        except MultiLevelBreak:
            continue
    return count

with open(sys.argv[1], 'r') as f:
    T = int(f.readline())
    i = 0
    while i < T:
        N, = map(int,f.readline().split())
        ab = [tuple(map(int,f.readline().split())) for i in range(N)]
        print("Case #%d: %s" % (i+1, fewest_levels(ab)))
        i += 1
