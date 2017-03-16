#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser


def repl(s, i, char):
    assert i < len(s)
    return s[:i] + char + s[i+1:]


def solve(c_str, j_str):
    all_c = [""]
    all_j = [""]
    for i, (c, j) in enumerate(zip(c_str, j_str)):
        if c == "?" and j == "?":
            ip_c = [str(i) for i in range(10)]
            ip_j = [str(i) for i in range(10)]
        elif c == "?" and j != "?":
            ip_c = [str(i) for i in range(10)]
            ip_j = [j]
        elif c != "?" and j == "?":
            ip_c = [c]
            ip_j = [str(i) for i in range(10)]
        elif c != "?" and j != "?":
            ip_c = [c]
            ip_j = [j]
        else:
            assert False

        all_c = [
            x + cc
            for x in all_c
            for cc in ip_c
        ]
        all_j = [
            x + jj
            for x in all_j
            for jj in ip_j
        ]
        assert len(all_c[0]) == len(all_j[0])

        _, best_c, best_j = min([
        (abs(int(ip_c) - int(ip_j)), ip_c, ip_j)
            for ip_c in all_c
            for ip_j in all_j
        ])

        all_c = [
            cc
            for cc in all_c
            if abs(int(cc) - int(best_c)) <= 10
        ]
        all_j = [
            jj
            for jj in all_j
            if abs(int(jj) - int(best_j)) <= 10
        ]

    _, best_c, best_j = min([
        (abs(int(ip_c) - int(ip_j)), ip_c, ip_j)
        for ip_c in all_c
        for ip_j in all_j
    ])
    return best_c, best_j


def main():
    inputfile = FileParser()
    T = inputfile.read_int()
    for test in range(1, T + 1):
        C, J = inputfile.read_strings()

        result = solve(C, J)

        print "Case #{}: {} {}".format(test, result[0], result[1])


if __name__ == '__main__':
    main()
