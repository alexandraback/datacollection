#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import sys


def read_tests(instance_file):
    with open(instance_file) as f:
        n = int(f.next().strip('\n'))
        for _ in range(n):
            _ = f.next()
            d = [int(i) for i in f.next().strip('\n').split(' ')]
            yield d


def min_time(d):
    d = sorted(d)

    if d == []:
        return 0

    m = d[-1] # max
    if m == 1:
        return m

    d_let_eat = [i-1 for i in d if i-1>0]




    if m % 2 == 0:
        d_split_biggest = d[:-1] + [m//2, m//2]
    else:
        d_split_biggest = d[:-1] + [m//2, m//2 + 1]

    return min(1 + min_time(d_let_eat), 1 + min_time(d_split_biggest))


def solve_instance(x):
    return min_time(x)


if __name__ == "__main__":
    if len(sys.argv[1:]) != 1:
        exit("Expected 1 argument, got %i" % len(sys.argv[1:]))

    instance_file = sys.argv[1]

    for i, instance in enumerate(
            read_tests(instance_file), start=1
            ):
        print("Case #%i: %s" % (i, solve_instance(instance)))
