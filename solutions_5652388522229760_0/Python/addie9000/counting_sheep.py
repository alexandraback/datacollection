import sys


def solve_case(n, case_number):
    count_flags = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    cur_n = n
    prev_n = 0
    count = 2
    while cur_n != prev_n:
        for c in str(cur_n):
            count_flags[int(c)] = 1

        if sum(count_flags) == 10:
            break

        prev_n = cur_n
        cur_n = n * count
        count += 1
    else:
        print("Case #%d: INSOMNIA" % case_number)
        return

    print("Case #%d: %d" % (case_number, cur_n))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        n = int(r.readline().strip())

        solve_case(n, case_number)


if __name__ == '__main__':
    main()