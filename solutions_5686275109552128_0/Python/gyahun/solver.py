from collections import namedtuple, Counter
from math import ceil

Test = namedtuple('Test', 'diners cakes')
def read(lines):
    diners = int(lines[0])
    return Test(diners, list(map(int, lines[1].split())))

def solve(test):
    counts = Counter(test.cakes)
    times = {ceil(c / d) for c in counts for d in range(1, c + 1)}
    getcost = lambda t: t + sum((ceil(c / t) - 1) * counts[c] for c in counts)
    return min(map(getcost, times))

if __name__ == '__main__':
    infile = 'B-small-attempt0.in'
    rows = 2

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
