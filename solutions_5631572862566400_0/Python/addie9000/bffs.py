import sys


def linked_len(s, passed, bffs):
    passed.append(s)
    while True:
        ns = bffs[s - 1]
        if ns in passed:
            break
        passed.append(ns)
        s = ns

    more_passed = passed[:]
    last_index = len(passed) - 1
    last_bff = bffs[passed[-1] - 1]
    candidate = []
    if passed[-2] == last_bff or passed[0] == last_bff:
        candidate.append(len(passed))

    while True:
        for index, bff in enumerate(bffs):
            if (index + 1) not in more_passed:
                if more_passed[-1] == bff:
                    more_passed.append(index + 1)
                    break
        else:
            break

    left_index = last_index - 1
    right_index = last_index + 1
    if right_index >= len(more_passed):
        right_index = -1
    if more_passed[left_index] == last_bff or more_passed[right_index] == last_bff:
        candidate.append(len(more_passed))

    if len(candidate) > 0:
        return max(candidate)
    else:
        return 0


def solve_case(n, bffs, case_number):
    max_linked_len = 0
    for i in range(1, n + 1):
        l = linked_len(i, [], bffs)
        if l > max_linked_len:
            max_linked_len = l

    print("Case #%d: %d" % (case_number, max_linked_len))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        n = int(r.readline().strip())
        bffs = [int(i) for i in r.readline().strip().split(' ')]

        solve_case(n, bffs, case_number)


if __name__ == '__main__':
    main()
