#!/usr/bin/python

import sys;
import os.path; 
from collections import *;
from Queue import *;

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def reads():
    return sys.stdin.readline().strip();

def nod(a, b):
    while b != 0:
        c = a % b;
        a = b;
        b = c;
    return a;    

def main():
    nt = readi();
    for t in range(1, nt+1):
        (P, Q) = [int(x) for x in reads().split('/')];
        nn = nod(P, Q);
        P = P / nn;
        Q = Q / nn;

        p2 = 1;
        while p2 < Q:
            p2 *= 2;
        if p2 != Q:    
            print "Case #%d: impossible" % t;
            continue;

        p2 = 1;
        i = 0;
        while p2 * P < Q:
            p2 *= 2;
            i += 1;

        print "Case #%d: %d" % (t, i);
    

main();
