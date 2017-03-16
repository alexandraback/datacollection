#!/usr/bin/python

import sys;
import os.path; 
from collections import *;
from Queue import *;
import numpy as np;

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def reads():
    return sys.stdin.readline().strip();

def main():
    nt = readi();
    for t in range(1, nt+1):
        (K, C, S) = readia();

        res = "IMPOSSIBLE"
        if K == 1:
            res = "1"
        elif C == 1:
            if S >= K:
                res = " ".join(str(x) for x in range(1, K + 1))
        elif S >= K - 1:
            res = " ".join(str(x) for x in range(2, K + 1))


        print "Case #%d: %s" % (t, res);
    

main();
