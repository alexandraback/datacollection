import queue
import sys


def flip(n):
    return int(str(n)[::-1])


def solve():
    n = int(input())
    q = [(1,1)]
    vis = set([1])
    while True:
        i, step = q.pop(0)

        if i == n:
            return step

        t = flip(i)
        if t not in vis:
            q.append((flip(i), step+1))
            vis.add(t)

        if i+1 not in vis:
            q.append((i+1, step+1))
            vis.add(i+1)

for kase in range(1, int(input()) + 1):
    print("Case #" + str(kase) + ": " + str(solve()))
    kase += 1
