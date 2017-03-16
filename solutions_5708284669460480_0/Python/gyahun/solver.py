from collections import namedtuple, Counter
from itertools import product
from re import findall

Test = namedtuple('Test', 'K L S key target')
def read(lines):
    K, L, S = map(int, lines[0].split())
    return Test(K, L, S, lines[1].strip(), lines[2].strip())

def solve(test):
    pat = '{}(?={})'.format(test.target[0], test.target[1:])
    strings = map(''.join, product(test.key, repeat=test.S))
    bananas = [len(findall(pat, s)) for s in strings]
    return max(bananas) - sum(bananas) / (test.K ** test.S)

if __name__ == '__main__':
    infile = 'B-small-attempt2.in'
    rows = 3

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            print()
            print(i)
            print(test)
            dst.write('Case #{}: {:.7f}\n'.format(i, solve(test)))
