from __future__ import (absolute_import, division,
                        print_function, unicode_literals)
import sys

from collections import deque

def solution(x):
    x_it = iter(x)
    answer = deque([next(x_it)])
    for l in x_it:
        if l >= answer[0]:
            answer.appendleft(l)
        else:
            answer.append(l)
    return "".join(answer)


def case(case_n, lines):
    x = next(lines).strip()
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
