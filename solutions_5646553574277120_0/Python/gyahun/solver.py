from collections import namedtuple
from itertools import product

Test = namedtuple('Test', 'C D V denoms')
def read(lines):
    C, D, V = map(int, lines[0].split())
    return Test(C, D, V, list(map(int, lines[1].split())))

def solve(test):
    moneys = product(*[[d * c for c in range(test.C + 1)] for d in test.denoms])
    amounts = set(map(sum, moneys))
    rest = set(range(1, test.V + 1)) - amounts
    print(rest)

    denoms = 0
    while rest:
        new = min(rest)
        news = [new * c for c in range(test.C + 1)]
        amounts |= set(map(sum, product(amounts, news)))
        rest -= amounts
        denoms += 1
        print(new, rest)
    return denoms

if __name__ == '__main__':
    infile = 'C-small-attempt1.in'
    rows = 2

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            print()
            print(i)
            print(test)
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
