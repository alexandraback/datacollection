import sys
import logging

logging.basicConfig(level=logging.DEBUG)
log = logging.getLogger(__name__)


def gen(s):
    if '?' not in s:
        yield s
    else:
        for i in range(10):
            for s2 in gen(s.replace('?', str(i), 1)):
                yield s2


def solve(case):
    log.info('Solving: %r', case)
    A, B = case.split()

    al = map(int, gen(A))
    bl = map(int, gen(B))

    comb = []

    for a in al:
        for b in bl:
            comb.append((abs(a-b), a, b, a+b))

    best = min(comb)

    return (('%%0%dd ' % len(A)) * 2).strip()  % (best[1], best[2])


def get_cases(lines):
    for ln in lines[1:]:
        yield ln


def main():
    lines = [ln.strip() for ln in sys.stdin]

    for i, case in enumerate(get_cases(lines), 1):
        result = solve(case)
        log.info('Case #%d: %s', i, result)
        print 'Case #%d: %s' % (i, result)


if __name__ == '__main__':
    main()

