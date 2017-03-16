from collections import namedtuple
from functools import reduce
from itertools import accumulate, product

array = 'bijkBIJK' # 1, i, j, k, -1, -i, -j, -k
muls = 'bijkBIJKiBkJIbKjjKBiJkbIkjIBKJibBIJKbijkIbKjiBkJJkbIjKBiKJibkjIB'
table = dict(zip(map(''.join, product(array, repeat=2)), muls))
mul = lambda x, y: table[x + y]

Test = namedtuple('Test', 'length rep txt')
def read(lines):
    length, rep = map(int, lines[0].split())
    return Test(length, rep, lines[1].strip())

def solve(test):
    acc = ''.join(accumulate(test.txt * test.rep, func=mul))
    imin = acc.find('i')
    possible = 0 <= imin <= acc.find('k', imin + 1) and acc[-1] == 'B'
    return 'YES' if possible else 'NO'

if __name__ == '__main__':
    infile = 'C-small-attempt1.in'
    rows = 2

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
