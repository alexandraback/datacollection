#!/usr/bin/python

"""Code Jam 2014 Qualification Round 2014"""

import sys

SUM = 2**40

def cal(idx, p, q):
    """docstring for cal"""
    #print p, q
    num = p * SUM
    if num % q:
        print "Case #%d: impossible" % (idx)
        return
    x = len(bin(num / q)) - 2
    print "Case #%d: %d" % (idx, 41 - x)

def main():
    """entry point"""
    input = sys.stdin.readlines()
    case_num = int(input[0])
    for i in range(case_num):
        line = input[i + 1].strip()
        sub_strs = line.split('/')
        cal(i+1, int(sub_strs[0]), int(sub_strs[1]))


if __name__ == '__main__':
    main()
