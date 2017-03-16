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
    for t in range(1, nt+1):
        line = sys.stdin.readline();
        (maxS, ss) = line.strip().split();
        maxS = int(maxS);
        ss = [int(c) for c in ss];

        if len(ss) != maxS + 1:
            print >>sys.stderr, "error: ", line;

        #print maxS;
        #print ss;

        numStanding = ss[0];
        res = 0;
        for i in range(1, len(ss)):
            #print i, ss[i], numStanding, res;
            if ss[i] > 0:
                if numStanding < i:
                    res += i - numStanding;
                    numStanding = i;
                numStanding += ss[i];
            #print i, ss[i], numStanding, res;
            #print;
            

        print "Case #%d: %d" % (t, res);
    

main();
