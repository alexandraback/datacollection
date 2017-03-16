from collections import namedtuple
from functools import reduce
from itertools import accumulate, product
from math import ceil

array = 'bijkBIJK' # 1, i, j, k, -1, -i, -j, -k
muls = 'bijkBIJKiBkJIbKjjKBiJkbIkjIBKJibBIJKbijkIbKjiBkJJkbIjKBiKJibkjIB'
table = dict(zip(map(''.join, product(array, repeat=2)), muls))
mul = lambda x, y: table[x + y]

Test = namedtuple('Test', 'length rep txt')
def read(lines):
    length, rep = map(int, lines[0].split())
    return Test(length, rep, lines[1].strip())

def solve(test):
    acc = ''.join(accumulate(test.txt * min(4, test.rep), func=mul))
    last = acc[test.length * (test.rep % 4) - 1]
    imin = acc.find('i')
    if imin < 0 or last != 'B': return 'NO'

    if imin < acc.find('k', imin + 1): return 'YES'
    index = acc.find('k')
    possible = index >= 0 and ceil((index + 1) / test.length) + 4 <= test.rep
    return 'YES' if possible else 'NO'

if __name__ == '__main__':
    infile = 'C-large.in'
    rows = 2

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.lout'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
