import sys


def solve_case(r, c, w, case_number):
    x = c / w
    rest = c % w
    print "Case #%d: %d" % (case_number, (x * r + w - 1 + (1 if rest > 0 else 0)))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        rcw = map(int, r.readline().strip().split(' '))

        solve_case(rcw[0], rcw[1], rcw[2], case_number)


if __name__ == '__main__':
    main()