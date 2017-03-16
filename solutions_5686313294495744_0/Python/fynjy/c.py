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
        n = readi();
        words1 = [];
        words2 = [];

        for i in range(n):
            (w1, w2) = reads().split();
            words1.append(w1);
            words2.append(w2);

        set1 = set(words1)
        set2 = set(words2)

        ans = min(len(words1) - len(set1), len(words2) - len(set2))
        print "Case #%d: %d" % (t, ans);
    

main();
