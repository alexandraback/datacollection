# coding: utf8

import sys


def main():
    t = int(sys.stdin.readline())
    for _t in range(t):
        j, p, s, k = [int(x) for x in sys.stdin.readline().strip().split()]
        days = min(j * p * s, j * p * k)
        print('Case #%s: %s' % (_t + 1, days))
        if j * p * s <= j * p * k:
            # Use all
            for _j in range(1, j + 1):
                for _p in range(1, p + 1):
                    for _s in range(1, s + 1):
                        print '%s %s %s' % (_j, _p, _s)
        else:
            # Limited
            for _j in range(1, j + 1):
                for _p in range(1, p + 1):
                    for _k in range(1, k + 1):
                        print '%s %s %s' % (_j, _p, _k)


if __name__ == '__main__':
    main()
