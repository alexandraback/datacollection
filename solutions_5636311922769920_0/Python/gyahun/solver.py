from collections import namedtuple
from itertools import groupby
from functools import reduce
from operator import or_

Test = namedtuple('Test', 'K C S')

def read(line):
    return Test(*map(int, line.split()))

def solve(test):
    K, C, S = test
    if K - C + 1 > S: return 'IMPOSSIBLE'

    groups = [list(g) for k, g in groupby(range(K), key=(lambda i: i // C))]
    arrays = [[g[0]] * (C - len(g)) + g if len(g) < C else g for g in groups]
    res = [1 + reduce(lambda x, y: K * x + y, a) for a in arrays]
    print(K, C, arrays)
    print(res)
    return res

if __name__ == '__main__':
    infile = 'D-small-attempt1.in'

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[1:]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, ' '.join(map(str, solve(test)))))
