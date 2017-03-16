import sys


def solve_case(s, case_number):
    result = [s[0]]
    for c in s[1:]:
        if result[0] > c:
            result.append(c)
        else:
            result.insert(0, c)
    print("Case #%d: %s" % (case_number, "".join(result)))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        s = r.readline().strip()

        solve_case(s, case_number)


if __name__ == '__main__':
    main()