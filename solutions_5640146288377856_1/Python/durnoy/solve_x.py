from __future__ import print_function
import collections
import heapq
import sys

f = sys.stdin

if len(sys.argv) > 1:
    f = open(sys.argv[1], "rt")

T = int(f.readline().strip())

def calc(R, C, W):
    if W == 1:
        return R * C

    n = (C // W) * R

    if C % W == 0:
        n += W - 1
    else:
        n += W

    return n

for case_id in range(1, T+1):
    R, C, W = map(int, f.readline().strip().split())

    r = calc(R, C, W)
    print(str.format('Case #{0}: {1}', case_id, r))
