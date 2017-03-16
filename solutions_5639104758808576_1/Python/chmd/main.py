#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import sys


def read_tests(instance_file):
    with open(instance_file) as f:
        n = int(f.next().strip('\n'))
        for _ in range(n):
            _, s_str = f.next().strip('\n').split(' ')
            s = [int(c) for c in s_str]
            yield s


def solve_instance(s):
    p = 0 # people clapping
    f = 0 # friends

    # for all shynesses
    for i in range(len(s)):
        # if necessary, add friends for people to clap
        if p + f < i:
            f += i - (p + f)
        # add the people to the clapping audience
        p += s[i]

    return f




if __name__ == "__main__":
    if len(sys.argv[1:]) != 1:
        exit("Expected 1 argument, got %i" % len(sys.argv[1:]))

    instance_file = sys.argv[1]

    for i, instance in enumerate(
            read_tests(instance_file), start=1
            ):
        print("Case #%i: %s" % (i, solve_instance(instance)))
