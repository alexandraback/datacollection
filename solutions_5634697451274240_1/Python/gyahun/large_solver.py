from collections import namedtuple
from itertools import groupby

Test = namedtuple('Test', 'S')

def read(line):
    return Test(*line.split())

def solve(test):
    return len(list(groupby(test.S))) - (test.S.endswith('+'))

if __name__ == '__main__':
    infile = 'B-large.in'

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[1:]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
