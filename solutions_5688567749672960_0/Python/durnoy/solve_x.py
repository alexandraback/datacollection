from __future__ import print_function
import collections
import heapq
import sys

f = sys.stdin

if len(sys.argv) > 1:
    f = open(sys.argv[1], "rt")

T = int(f.readline().strip())

def rev(x):
    return int(str.join('', reversed(str(x))))

def calc(N):
    count = 0
    visited = set()

    next_items = [1]

    while next_items:
        count += 1
        new = []
        def add(x, y):
            if y <= N and y > x and y not in visited:
                visited.add(y)
                new.append(y)
        found = False
        for x in next_items:
            if x == N:
                found = True
                break
            add(x, x+1)
            add(x, rev(x))
        #~ print(new)
        if found: break
        next_items = new

    return count

for case_id in range(1, T+1):
    N = int(f.readline().strip())

    r = calc(N)
    print(str.format('Case #{0}: {1}', case_id, r))
