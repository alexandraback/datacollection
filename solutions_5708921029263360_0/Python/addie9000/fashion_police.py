import itertools
import sys


def solve_case(j, p, s, k, case_number):
    jps = j * p * s
    jp = j * p
    ps = p * s
    js = j * s
    maxdays = min(min(jp, ps, js) * k, jps)

    print("Case #%d: %d" % (case_number, maxdays))

    jj = list(range(1, j + 1))
    pp = list(range(1, p + 1))
    ss = list(range(1, s + 1))
    kk = list(range(1, k + 1))

    if maxdays == jps:
        patterns = list(itertools.product(jj, pp, ss))
    else:
        m = min(jp, ps, js)

        if m == jp:
            patterns = list(itertools.product(jj, pp, kk))
        elif m == ps:
            patterns = list(itertools.product(kk, pp, ss))
        else:
            patterns = list(itertools.product(jj, kk, ss))

    for pattern in patterns:
        print(" ".join(map(str, pattern)))



def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        jpsk = map(int, r.readline().split(' '))

        solve_case(jpsk[0], jpsk[1], jpsk[2], jpsk[3], case_number)


if __name__ == '__main__':
    main()
