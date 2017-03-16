"""
https://code.google.com/codejam/contest/6254486/dashboard
"""

if False:
    import random
    with open('big_sheep.in', 'w') as f:
        cases = 2**16
        f.write(str(cases) + '\n')
        for _ in range(cases):
            f.write(str(random.randint(0, 10**6)) + '\n')


import fileinput
import itertools

lines = fileinput.input()

cases = int(next(lines))

for case in range(1, cases + 1):
    n = int(next(lines))

    digits = set()
    if n == 0:
        ans = 'INSOMNIA'
    else:
        digits = digits.union(set(str(n)))
        i = 0
        while len(digits) != 10:
            i += 1
            digits = digits.union(set(str(n * i)))
        ans = str(n * i)

    print('Case #{case}: {ans}'.format(**locals()))
