"""
https://code.google.com/codejam/contest/6254486/dashboard#s=p1
"""

import fileinput

lines = fileinput.input()

cases = int(next(lines))

for case in range(1, cases + 1):
    s = next(lines).strip()

    # Starting at the bottom, count the number times the happiness of the pancakes changes
    flips = 0
    prev = '+'
    for c in reversed(s):
        if c != prev:
            flips += 1
        prev = c

    print("Case #{case}: {flips}".format(**locals()))
