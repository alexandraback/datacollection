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
        n = readi();
        if n == 0:
            print "Case #%d: INSOMNIA" % t;
            continue;

        seenDigits = [False] * 10;
        nOrig = n;
        while True:
            n1 = n;
            while n1 != 0:
                seenDigits[n1 % 10] = True;
                n1 //= 10;
            # print n, seenDigits;

            if all(seenDigits):
                break;
            n += nOrig;
            


        print "Case #%d: %d" % (t, n);
    

main();
