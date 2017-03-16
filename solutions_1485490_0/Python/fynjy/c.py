#!/usr/bin/python

import sys;
import os.path; 
THIS_DIR = os.path.dirname(sys.argv[0]);
sys.path.append(THIS_DIR + '/..')
from util import *;

class CellInfo:
    def __init__(self):
        self.maxToys = 0;
        self.da = 0;
        self.db = 0;
        self.leftFromA = 0;
        self.leftFromB = 0;
        self.aType = 0;
        self.bType = 0;

def main():
    nt = readi();
    for t in range(1, nt+1):
        (N, M) = readia();
        A = readia();
        B = readia();
        aTypes = [];
        bTypes = []
        if N*2 != len(A):
            raise Exception("error A");
        if M*2 != len(B):
            raise Exception("error B");
        for i in range(N):
            if len(aTypes) == 0 or aTypes[-1][1] != A[i*2+1]:
                aTypes.append((A[i*2], A[i*2+1]));
            else:
                aTypes[-1] = (A[i*2] + aTypes[-1][0], aTypes[-1][1]); 

        for i in range(M):
            if len(bTypes) == 0 or bTypes[-1][1] != B[i*2+1]:
                bTypes.append((B[i*2], B[i*2+1]));
            else:
                bTypes[-1] = (B[i*2] + bTypes[-1][0], bTypes[-1][1]); 
        #if N != len(aTypes):
        #    print >>sys.stderr, t, "n", N, len(aTypes);
        #if M != len(bTypes):
        #    print >>sys.stderr, t, "m", M, len(bTypes);
        N = len(aTypes);
        M = len(bTypes);
        #print aTypes;
        #print bTypes;
        
        tab = [[CellInfo() for b in bTypes] for a in aTypes]
        #print tab;

        for ai in range(N):
            for bi in range(M):
                tab[ai][bi].leftFromA = aTypes[ai][0];
                tab[ai][bi].aType = aTypes[ai][1];
                tab[ai][bi].leftFromB = bTypes[bi][0];
                tab[ai][bi].bType = bTypes[bi][1];

        for ai in range(N):
            for bi in range(M):
                c = tab[ai][bi];
                maxConsumed = 0;
                consumed = 0;

                fromA = False;
                fromB = False;
                if ai > 0:
                    c1 = tab[ai-1][bi];
                    if c1.aType == c1.bType:
                        consumed = min(c1.leftFromA, c1.leftFromB);
                    else:
                        consumed = 0;
                    #print "consider a ", consumed, c1.maxToys, maxConsumed;
                    if consumed + c1.maxToys >= maxConsumed:
                        maxConsumed = consumed + c1.maxToys;
                        fromA = True;
                if bi > 0:
                    c1 = tab[ai][bi-1];
                    if c1.aType == c1.bType:
                        consumed = min(c1.leftFromA, c1.leftFromB);
                    else:
                        consumed = 0;
                    #print "consider b ", consumed, c1.maxToys, maxConsumed;
                    if consumed + c1.maxToys >= maxConsumed:
                        maxConsumed = consumed + c1.maxToys;
                        fromB = True;
                        fromA = False;


                c.maxToys = maxConsumed;
                if fromA:
                    c1 = tab[ai-1][bi];
                    if c1.aType == c1.bType:
                        consumed = min(c1.leftFromA, c1.leftFromB);
                    else:
                        consumed = 0;
                    c.leftFromB = max(c1.leftFromB - consumed, 0);
                    #print "fromA! ", c1.leftFromA, c1.leftFromB, consumed;
                elif fromB:
                    c1 = tab[ai][bi-1];
                    if c1.aType == c1.bType:
                        consumed = min(c1.leftFromA, c1.leftFromB);
                    else:
                        consumed = 0;
                    c.leftFromA = max(c1.leftFromA - consumed, 0);
                    #print "fromB! ", c1.leftFromA, c1.leftFromB, consumed;
                #print ai, bi, "typeA", chr(ord('a') + c.aType - 1), c.leftFromA, "typeB", chr(ord('a') + c.bType - 1), c.leftFromB, "fromA", fromA, "fromB", fromB, consumed, maxConsumed;
    
        lastC = tab[N-1][M-1];
        maxToys = lastC.maxToys;
        if lastC.aType == lastC.bType:
            maxToys += min(lastC.leftFromA, lastC.leftFromB);

        print "Case #%d: %d" % (t, maxToys);
    

main();
