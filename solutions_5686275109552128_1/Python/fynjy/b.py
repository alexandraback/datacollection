#!/usr/bin/python

import sys;
import os.path; 

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def calc(P, maxPiece):
    totalCuts = 0;
    found = False;
    for p in P:
        if p >= maxPiece:
            cuts = p // maxPiece - 1;
            if p % maxPiece != 0:
                cuts += 1;
            totalCuts += cuts;
            found = True;
    if not found:
        print >>sys.stderr, "error in calc ", maxPiece;
    return totalCuts + maxPiece;

def main():
    nt = readi();
    for t in range(1, nt+1):
        D = readi();
        P = readia();
        #print D, P;
        if len(P) != D:
            print >>sys.stderr, "error ", t;

        bestRes = calc(P, 1);
        #print "for 1 got", bestRes;
        for i in range(2, max(P) + 1):
        #for i in range(2, 510):
            resI = calc(P, i);
            if resI < bestRes:
                bestRes = resI;
                #print "for ", i, " got better: ", bestRes;
            #elif resI > bestRes:
            #    print "for ", i, " got worse: ", resI;

        print "Case #%d: %d" % (t, bestRes);
    

main();
