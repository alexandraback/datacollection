#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())


def do_mm(cnum, R, C, E):
    #print "Case #%d: %d %d %d" % (cnum, R, C, E)
    print "Case #%d:" % (cnum,)
    if R==1:
        print "c" + (E-1)*"." + (C-E)*"*"
        return
    elif C==1:
        print (R-E)*"*\n" + (E-1)*".\n" + "c"
        return
    elif E==1:
        for i in range(R-1):
            print C*"*"
        print "c" + (C-1)*"*"
        return

#   for S in range(1):
#       for A in range(1,R):
#           for B in range(1,C):
    for S in range(2, R+C-1):
        for A in range(1,R):
            B = S-A
            if 1<= B < C:
                if 2*(A+B) <= E <= (A+1)*(B+1):
                    F = (A+1)*(B+1) - E
                    for i in range(R-A-1):
                        print C*"*"
                    for i in range(A-1):
                        m = min(B-1, F)
                        print ".." + (B-1-m)*"." + (m+C-B-1)*"*"
                        F -= m
                    print (B+1)*"." + (C-B-1)*"*"
                    print "c" + B*"." + (C-B-1)*"*"
                    return

    print "Impossible"



def do_one_case(cnum):
    (R, C, M) = rdints()
    E = R*C - M
    do_mm(cnum, R, C, E)

def test_mm():
    d = set((2, 3, 5, 7))
    for S in range(6,31):
        for R in range(3,S-2):
            C = S-R
            for E in range(1, R*C+1):
                if E not in d:
                    do_mm(123, R, C, E)
    exit(0)


def main():
    #test_mm()
    N = rd1int()
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
