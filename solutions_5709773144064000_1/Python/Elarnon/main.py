#!/usr/bin/env python3

from decimal import Decimal
from sys import stdin
from random import randint

def solve(c, f, x):
    cookies = float(0)
    production = float(2)
    time = 0
    while cookies < x:
        no_farm = (x - cookies) / production
        wait_farm = (c - cookies) / production
        with_farm = wait_farm + x / (production + f)
        if with_farm < no_farm:
            time += wait_farm
            production += f
        else:
            time += no_farm
            cookies = x
    return time

def fuzzy(k):
    for i in range(0, k):
        c = Decimal(randint(1, 1000000000)) / Decimal(100000)
        f = Decimal(randint(1, 100 * 100000)) / Decimal(100000)
        x = Decimal(randint(1, 100000 * 100000)) / Decimal(100000)
        solve(c, f, x)

if __name__ == '__main__':
    ncases = int(stdin.readline())
    for i in range(1, ncases + 1):
        [c, f, x] = [float(x) for x in stdin.readline().split()]
        print("Case #{}: {:.7f}".format(i, solve(c, f, x)))