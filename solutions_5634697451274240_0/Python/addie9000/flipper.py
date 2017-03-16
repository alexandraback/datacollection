import sys


def flip(pancakes, i):
    return [not x for x in reversed(pancakes[0:i])] + pancakes[i:]


def switched_index(pancakes):
    index = 0
    for p in pancakes:
        if not p == pancakes[0]:
            break
        index += 1
    return index


def solve_case(pancakes, case_number):
    count = 0
    while False in pancakes:
        pancakes = flip(pancakes, switched_index(pancakes))
        count += 1

    print("Case #%d: %d" % (case_number, count))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        ps = ['+' == x for x in list(r.readline().strip())]

        solve_case(ps, case_number)


if __name__ == '__main__':
    main()
