from collections import namedtuple
from itertools import accumulate

Test = namedtuple('Test', 'level stats')

def read(line):
    number, stats = line.split()
    return Test(int(number), list(map(int, stats)))

def solve(test):
    return max(max(n - s for n, s in enumerate(accumulate(test.stats), 1)), 0)

if __name__ == '__main__':
    infile = 'A-large.in'

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[1:]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
