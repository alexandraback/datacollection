import os
from random import choice
from collections import defaultdict


CUR_DIR = os.path.dirname(os.path.realpath(__file__))


def read_test(f):
    with open(f, 'r') as ifs:
        t = []
        for case in ifs.read().split('\n')[1:]:
            line = case.strip()
            if line:
                t.append(case.strip())
        return t


def solve_case(case):
    order = [('Z', 'ZERO', '0'),
             ('W', 'TWO', '2'),
             ('X', 'SIX', '6'),
             ('G', 'EIGHT', '8'),
             ('U', 'FOUR', '4'),
             ('F', 'FIVE', '5'),
             ('V', 'SEVEN', '7'),
             ('I', 'NINE', '9'),
             ('O', 'ONE', '1'),
             ('T', 'THREE', '3')]
    f = defaultdict(int)
    res = []
    for c in case:
        f[c] += 1
    for item in order:
        c, s, x = item
        v = f[c]
        for z in s:
            assert f[z] >= v
            f[z] -= v
        res.extend([x] * v)
    return ''.join(sorted(res))


def solve(cases):
    for case in cases:
        yield solve_case(case)


def save(f, asnwers):
    with open(f, 'w') as ofs:
        for case, ans in enumerate(asnwers):
            ofs.write('Case #%d: %s\n' % (case + 1, ans))


def main():
    for f in os.listdir(CUR_DIR):
        if f.startswith('A') and f.endswith('.in') or f == 'input.in':
            print(f)
            tests = read_test(f)
            answers = solve(tests)
            save(CUR_DIR + os.path.sep + f.replace('.in', '.out'), answers)
            print('Done!')


if __name__ == '__main__':
    main()
