#!/usr/bin/env python

import sys


def new_lottery_game(a, b, k):
    result = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                result += 1

    return result


def main():
    with open(sys.argv[1], 'r') as fi:
        n_case = int(fi.readline())

        r_case = 0
        while r_case < n_case:
            r_case += 1

            a, b, k = [int(i) for i in fi.readline().split(' ')]
            result = new_lottery_game(a, b, k)
            print('Case #{0}: {1}'.format(r_case, result))

if __name__ == '__main__':
    main()
