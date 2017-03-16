#!/usr/bin/env python

def pair_cnt_brute_force(a, b, k):
    pair_cnt = 0
    for aa in xrange(a):
        for bb in xrange(b):
            if aa & bb < k:
                pair_cnt += 1
    return pair_cnt

def solve(line):
    numbers = [int(n) for n in line.split()]
    a = numbers[0]
    b = numbers[1]
    k = numbers[2]

    return pair_cnt_brute_force(a, b, k)



import sys
#import pdb

if __name__ == '__main__':
    filename_prefix = sys.argv[1]
    filename_in = filename_prefix + ".in"
    filename_out = filename_prefix + ".out"

    with open(filename_in, 'r') as file_in:
        lines = file_in.readlines()

    testcnt = int(lines[0])
    idx = 1

    with open(filename_out, 'w') as file_out:
        #pdb.set_trace()
        for test in range(testcnt):
            res = solve(lines[idx])
            file_out.write("Case #%d: %d\n" % (test + 1, res))
            idx += 1
