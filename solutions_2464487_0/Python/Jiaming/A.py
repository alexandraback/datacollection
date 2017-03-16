#!/usr/bin/env pypy

import sys

def parse_case(in_file):
    return map(int,in_file.readline().split())

def solve(case):
    r,t = case
    n = 1
    x = 0
    while True:
        nx = x +  2*r+4*n-3
        if nx > t:
            return str(n-1)
        n += 1
        x = nx

if __name__ == '__main__':
    in_file  = open(sys.argv[1]+'.in')
    out_file = open(sys.argv[1]+'.out','w')

    T = int(in_file.readline())
    for t in xrange(1,T+1):
        case = parse_case(in_file)
        out_file.write("Case #%d: %s\n" % (t, solve(case)))
    
    in_file.close()
    out_file.close()
