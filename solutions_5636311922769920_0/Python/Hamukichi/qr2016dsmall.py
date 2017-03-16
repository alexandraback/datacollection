#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def solve_small(k, c):
    return list(range(1, k + 1))


def main():
    t = int(input())
    for i in range(1, t + 1):
        k, c, s = map(int, input().split())
        assert s == k
        print("Case #{}: {}".format(i, " ".join(map(str, solve_small(k, c)))))


if __name__ == '__main__':
    main()
