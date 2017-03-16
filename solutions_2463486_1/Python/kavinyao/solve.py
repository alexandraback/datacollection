# -*- coding:utf-8 -*-

import os
import sys

# precomputed FS numbers up to 10^16 with precompute.py
fair_and_squares = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004]

def solve(A, B):
    """Get number of fair and square numbers no smaller than A and no bigger than B."""
    return len(filter(lambda x: A <= x <= B, fair_and_squares))


if __name__ == '__main__':
    in_file = sys.argv[1]
    out_file = os.path.splitext(in_file)[0] + '.out'
    #print out_file
    output = open(out_file, 'w')

    with open(in_file) as test:
        rounds = int(test.next())
        #print rounds, 'rounds'

        for i in xrange(rounds):
            A, B = map(int, test.next().split())
            #print A, B

            res = solve(A, B)
            #print res
            output.write("Case #%d: %s\n" % (i+1, res))
            #print

    output.close()
