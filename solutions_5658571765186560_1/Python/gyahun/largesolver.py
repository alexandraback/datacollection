from collections import namedtuple
from math import ceil

ric, gab = 'RICHARD', 'GABRIEL'

Test = namedtuple('Test', 'x r c')
def read(lines):
    return Test(*map(int, lines[0].split()))

def solve(test):
    if (test.r * test.c) % test.x != 0 or test.x >= 7: return ric

    minlen = min(test.r, test.c)
    if minlen == 1 and test.x >= 3: return ric
    if minlen == 2 and test.x >= 4: return ric
    if minlen == 3 and test.x >= 5: return ric
    return gab

if __name__ == '__main__':
    infile = 'D-large.in'
    rows = 1

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
