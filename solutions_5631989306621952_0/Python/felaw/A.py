#!/usr/bin/env python3

import sys

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

def loop_pairs(lst):
    assert len(lst) > 0
    a = lst[0]
    for b in lst[1:]:
        yield a, b
        a = b


def test_case(inp):
    res = inp[0]
    for a, b in loop_pairs(inp):
        if b >= res[0]:
            res = '%s%s' % (b, res)
        else:
            res = '%s%s' % (res, b)

    return res


####################################################################
#                              I/O                                 #
####################################################################

def main():
    ################################################################
    # Define input and output
    in_file_name = 'A-small-attempt0.in'
    out_file_name = in_file_name.rstrip('.in') + '.out'
    # will be closed by garbage collector
    orig_stdout = sys.stdout
    sys.stdin = open(in_file_name)
    sys.stdout = open(out_file_name, "w")
    ################################################################

    for i in range(read_int()):
        solution = test_case(input())
        print(".", file=orig_stdout, end='')
        print("Case #%s: %s" % (i+1, solution))

if __name__ == '__main__':
    main()
