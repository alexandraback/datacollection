from collections import namedtuple

Test = namedtuple('Test', 'R C W')
def read(lines):
    return Test(*map(int, (lines[0].split())))

def solve(test):
    q = test.C // test.W - 1
    return q + min(test.W + 1, test.C - test.W * q) + (q + 1) * (test.R - 1)


if __name__ == '__main__':
    infile = 'A-large.in'
    rows = 1

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            print()
            print(i, test)
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
