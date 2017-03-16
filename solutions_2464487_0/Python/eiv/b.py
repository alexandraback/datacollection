#!/usr/bin/env python

import sys
from math import floor, sqrt

def Solve(r, t):
    n = floor((1-2*r+sqrt(4*r**2-4*r+1+8*t))/4.0)
    while(2*n**2+(2*r-1)*n-t > 0): n = n - 1
    return str(int(n))

def main():
    infile = open(sys.argv[1], 'r')
    inp = infile.readlines()
    T = int(inp[0])
    strn = 1
    for i in range(T):
        (r, t) = map(int, inp[strn].split())
        strn += 1
        print 'Case #'+str(i+1)+': '+Solve(r, t)
   


if __name__=='__main__':
    main()
