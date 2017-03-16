#!/usr/bin/env pypy

import sys

def parse_case(in_file):
    E,R,N = map(int,in_file.readline().split())
    return E,R,N,map(int,in_file.readline().split())

def solve(case):
    E,R,N,A = case
    D = dict([(i,[0 for i in xrange(E+1)]) for i in xrange(len(A))])
    D[0] = [(E-i) * A[0] for i in xrange(E+1)]
    for ai in xrange(1,len(A)):
        for i in xrange(E+1):
            x = 0
            for oi in xrange(max(0,i-R),E+1):
                x = max(x, D[ai-1][oi] + (min(E,oi+R)-i) * A[ai])
            D[ai][i] = x
    return str(max(D[len(A)-1]))

if __name__ == '__main__':
    in_file  = open(sys.argv[1]+'.in')
    out_file = open(sys.argv[1]+'.out','w')

    T = int(in_file.readline())
    for t in xrange(1,T+1):
        case = parse_case(in_file)
        out_file.write("Case #%d: %s\n" % (t, solve(case)))
    
    in_file.close()
    out_file.close()
