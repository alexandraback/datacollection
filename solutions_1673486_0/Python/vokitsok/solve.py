import sys
import re


def handle_case(case_num):
    A, B = map(int, sys.stdin.readline().split())
    ps = map(float, sys.stdin.readline().split())

    res = B + 2
    prob = 1.
    for backspaces in range(A, -1, -1):
        if (A > backspaces):
            prob *= ps[A - backspaces - 1]
        # import pdb; pdb.set_trace()
        tmp = prob * (backspaces * 2. + B - A + 1) + (1 - prob) * (backspaces * 2 + B + 1 + B - A + 1)
        # print 'A = %s B = %s' % (A, B)
        # print 'b %s r %0.6f pr %0.6f' % (backspaces, tmp, prob)
        res = min(tmp, res)
    print 'Case #%s: %0.6f' % (case_num, res)


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()