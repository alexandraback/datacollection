import sys, math


def forward(ahead_block, current_relative, k):
    ahead_block = ahead_block * k + current_relative - 1
    if current_relative < k:
        current_relative += 1
    return ahead_block, current_relative


def solve_case(k, c, s, case_number):
    min_s = math.ceil(k / c)
    if s < min_s:
        print("Case #%d: IMPOSSIBLE" % case_number)
        return

    current_relative = 0
    keys = []
    for i in range(0, min_s):
        current_relative += 1
        ahead_block = 0
        for j in range(1, c):
            ahead_block, current_relative = forward(ahead_block, current_relative, k)
        keys.append(ahead_block * k + current_relative)

    print("Case #%d: %s" % (case_number, " ".join([str(key) for key in keys])))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        kcs = [int(x) for x in r.readline().strip().split(' ')]

        solve_case(kcs[0], kcs[1], kcs[2], case_number)


if __name__ == '__main__':
    main()
