#!/usr/bin/python3.4
import sys


def wp(n, k):
    n = sorted(n)
    k = sorted(k)
    score = 0
    for v in n:
        k_choice = next((x for x in k if x > v), k[0])
        k.remove(k_choice)
        if v > k_choice:
            score += 1
    return score

Z = int(sys.stdin.readline().strip())

for test in range(Z):
    N = int(sys.stdin.readline().strip())
    n = [float(x) for x in sys.stdin.readline().strip().split()]
    k = [float(x) for x in sys.stdin.readline().strip().split()]
    print("Case #%d: %d %d" % (test + 1, N - wp(k, n), wp(n, k)))