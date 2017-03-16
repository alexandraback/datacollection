from collections import namedtuple
from itertools import product, islice

Test = namedtuple('Test', 'N J')
            
def read(line):
    return Test(*map(int, line.split()))

def genprimes(lim):
    primes = [2]
    yield 2
    for n in range(3, lim, 2):
        if all(n % p for p in primes):
            yield n
            primes.append(n)

def solve(test):
    prds = product('01', repeat=(test.N - 2))
    inputs = ('1{}1'.format(''.join(map(str, p))) for p in prds)

    ans = []
    while len(ans) < test.J:
        i = next(inputs)
        qs = []
        for n in (int(i, b) for b in range(2, 11)):
            q = next((d for d in islice(genprimes(n), 100) if n % d == 0), None)
            if not q: break
            qs.append(q)
        else: ans.append([i] + qs)

    return ans

if __name__ == '__main__':
    infile = 'C-large.in'

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[1:]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}:\n'.format(i))
            for line in solve(test):
                dst.write(' '.join(map(str, line)) + '\n')
