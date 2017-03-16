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
    assert R == 1

    if C % W == 0:
        return C // W + W - 1
    else:
        return C // W + W

for case_id in range(1, T+1):
    R, C, W = map(int, f.readline().strip().split())

    r = calc(R, C, W)
    print(str.format('Case #{0}: {1}', case_id, r))
