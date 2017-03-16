import itertools
import math
import sys


def solve_case(b, m, case_number):
    # 1 -> b
    w = 1
    if b > 2:
        for i in range(1, (b - 2) + 1):
            w += (b - 2) * (math.factorial((b - 2))) / math.factorial(i) + 1
    if m > w:
        print("Case #%d: IMPOSSIBLE" % case_number)
        return
    print("Case #%d: POSSIBLE" % case_number)
    b2 = b - 2
    base = list(range(1, b))
    pattern = []
    w = 1
    bmap = [[0 for i in range(b)] for j in range(b)]
    bmap[0][b - 1] = 1

    for i in range(1, b2 + 1):
        w += 1
        if w > m:
            break
        bmap[0][i] = 1
        bmap[i][b - 1] = 1
    if w < m:
        for i in range(2, b):
            n = b2 * (math.factorial(b2)) / math.factorial(i)
            pp = [p for p in itertools.permutations(base, i) if p[0] != 1]
            if n + w <= m:
                pattern.extend(pp)
                w += n
            else:
                pattern.extend(pp[:m - w])
                break
        for bbs in pattern:
            prev = 0
            for bb in bbs:
                bmap[prev][bb - 1] = 1
                prev = bb - 1
            bmap[prev][b - 1] = 1

    for line in bmap:
        print("".join(map(str, line)))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        bm = map(int, r.readline().split(' '))

        solve_case(bm[0], bm[1], case_number)


if __name__ == '__main__':
    main()
