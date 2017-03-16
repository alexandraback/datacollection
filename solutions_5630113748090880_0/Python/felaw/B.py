#!/usr/bin/env python3

import sys
from collections import Counter

####################################################################
#                           Helpers                                #
####################################################################


def read_int():
    return int(input())


def read_ints():
    return [int(s) for s in input().split()]


####################################################################
#                           Solution                               #
####################################################################

def test_case(nums):
    res = []
    for k, v in Counter(nums).items():
        if v % 2 == 1:
            res.append(k)
    res.sort()
    return ' '.join(str(n) for n in res)


####################################################################
#                              I/O                                 #
####################################################################

def main():
    ################################################################
    # Define input and output
    in_file_name = 'B-small-attempt1.in'
    out_file_name = in_file_name.rstrip('.in') + '.out'
    # will be closed by garbage collector
    orig_stdout = sys.stdout
    sys.stdin = open(in_file_name)
    sys.stdout = open(out_file_name, "w")
    ################################################################

    for i in range(read_int()):
        nums = []
        n = read_int()
        for _ in range(n*2-1):
            nums += read_ints()
        solution = test_case(nums)
        print(".", file=orig_stdout, end='')
        print("Case #%s: %s" % (i+1, solution))
    print("\nsaved to %s" % out_file_name, file=orig_stdout, end='')


if __name__ == '__main__':
    main()
