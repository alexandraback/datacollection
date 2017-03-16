#!/usr/bin/python

import sys;
import os.path; 

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def main():
    nt = readi();
    for c in range(1, nt+1):
        (C, F, X) = readfa();

        numFarms = 0;
        bestTotalTime = 1e100;
        curTime = 0;

        while True:
            t = curTime + X / (2.0 + F * numFarms);
            if t > bestTotalTime:
                break;
            bestTotalTime = t;
            curTime += C / (2.0 + F * numFarms);
            numFarms += 1;

        print "Case #%d: %.7f" % (c, bestTotalTime);
        #print "numFarms: ", (numFarms - 1);
    

main();
