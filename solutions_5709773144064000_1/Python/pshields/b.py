#!/usr/bin/python3.4
import os
import sys


# However many cookie farms you need to buy, you should buy them as early as
# possible.

def solve(c, f, x):
    farms = 0
    time_to_acquire_farms = 0.0
    cost = time_to_acquire_farms + x / 2
    prev_cost = cost + 1
    while cost < prev_cost:
        # Try adding one more farm.
        time_to_acquire_farms += c / (2 + farms * f)
        farms += 1
        prev_cost = cost
        cost = time_to_acquire_farms + x / (2 + farms * f)
    return prev_cost

if __name__ == '__main__':

    Z = int(sys.stdin.readline().strip())

    for test in range(Z):
        c, f, x = [float(X) for X in sys.stdin.readline().strip().split()]
        print("Case #%d: %.7f" % (test + 1, solve(c, f, x)))
