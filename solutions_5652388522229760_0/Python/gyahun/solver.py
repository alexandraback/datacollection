from collections import namedtuple

Test = namedtuple('Test', 'N')

def read(line):
    return Test(int(line))

def solve(test):
    print(test.N)
    if not test.N: return 'INSOMNIA'

    numbers = set()
    t = 0
    while len(numbers) < 10:
        t += test.N
        numbers |= set(str(t))
    return t

if __name__ == '__main__':
    infile = 'A-small-attempt1.in'

    with open(infile) as src:
        lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(line) for line in lines[1:]]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
