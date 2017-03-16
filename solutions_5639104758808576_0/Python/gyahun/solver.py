from collections import namedtuple
from itertools import accumulate

Test = namedtuple('Test', 'level stats')

def read(line):
    (number,), stats = [list(map(int, digits)) for digits in line.split()]
    return Test(number, stats)

def solve(test):
    m = max(lvl - s for lvl, s in enumerate(accumulate(test.stats), 1))
    return max(m, 0)

if __name__ == '__main__':
    infile = 'A-small-attempt0.in'

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[1:]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
