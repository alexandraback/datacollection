# -*- coding: utf-8 -*-

import itertools
import sys


def solve():
    N = int(input())
    s = input().split()
    ans = 0

    middles = list()

    for e in s:
        if len(e) >= 3:
            middles.append(e[1:-1])

    for i in range(len(middles)):
        for j in range(i + 1, len(middles)):
            if set(middles[i]) & set(middles[j]) != 0:
                return ans

    for case in itertools.permutations(s, N):
        flag = True
        for i in range(N):
            if case[i][0] != case[i][-1]:
                for j in range(i + 1, N):
                    if case[i][0] in case[j]:
                        flag = False
                if i < N - 1 and case[i + 1][0] != case[i][-1]:
                    for j in range(i + 1, N):
                        if case[i][-1] in case[j]:
                            flag = False
            else:
                if i < N - 1 and case[i + 1][0] != case[i][0]:
                    for j in range(i + 1, N):
                        if case[i][0] in case[j]:
                            flag = False
        if flag:
            ans += 1

    return ans

def main():
    T = int(input())
    for i in range(1, T + 1):
        print('Case #{}: {}'.format(i, solve()))

if __name__ == '__main__':
    sys.exit(main())
