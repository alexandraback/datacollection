from __future__ import (absolute_import, division,
                        print_function, unicode_literals)
import sys


from collections import Counter


def solution(x):
    counter = Counter()
    for l in x:
        for n in l:
            counter[n] += 1

    cand = []
    for n, v in counter.items():
        if v % 2 != 0:
            cand.append(n)
    cand.sort()
    return " ".join(str(n) for n in cand)


def case(case_n, lines):
    N = int(next(lines))
    x = [list(map(int, next(lines).split())) for i in range(2 * N - 1)]
    answer = solution(x)
    print("Case #{0}: {1}".format(case_n, answer))


def main(in_lines):
    N = int(next(in_lines))
    for i in range(N):
        case(i+1, in_lines)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        with open(sys.argv[1]) as fd:
            main(fd)
    else:
        main(sys.stdin)
