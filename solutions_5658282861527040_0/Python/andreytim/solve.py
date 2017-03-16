#!/usr/bin/python

import sys

def solve_test_case(A, B, K):
    total = 0
    for a in range(0, A):
        for b in range(0, B):
            if a & b < K:
                total += 1
    return total

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        line = f.readline()
        A, B, K = (int(s) for s in line.strip().split(' '))
        print 'Case #%d: %d' % (i, solve_test_case(A, B, K))

if __name__ == '__main__':
    main()
