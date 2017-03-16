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

def main():
    nt = readi();
    for t in range(1, nt+1):
        s = reads();
        prev = s[0];
        nGroups = 0;
        for c in s:
            if c != prev:
                nGroups += 1;
                prev = c;

        nRot = nGroups;
        if nRot % 2 == 1 and s[0] == '+' or nRot % 2 == 0 and s[0] == '-':
            nRot += 1;
        print "Case #%d: %d" % (t, nRot);
    

main();
