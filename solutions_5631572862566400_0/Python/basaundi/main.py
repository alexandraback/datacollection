from __future__ import (absolute_import, division,
                        print_function, unicode_literals)
import sys


def solution(n, l):
    st = [[i+1, bff] for i, bff in enumerate(l)]
    for f in st:
        while True:
            bff = f[-1]
            nu = l[bff-1]
            if nu in f:
                break
            f.append(nu)
    for maxf in st:
        last = maxf[-1]-1
        if l[last] != maxf[-2] and l[last] != maxf[0]:
            maxf.pop()

    combs = []
    for f1 in st:
        for f2 in st:
            if f2[0] in f1:
                combs.append(len(f1))
                continue
            for i in f1:
                if i in f2:
                    # print(f1.index(i) + f2.index(i) - 1, f1, f2)
                    combs.append(f1.index(i) + f2.index(i) - 1)
                else:
                    combs.append(len(f1))
    return max(combs)


def case(case_n, lines):
    n = int(next(lines))
    x = list(map(int, next(lines).split()))
    answer = solution(n, x)
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
