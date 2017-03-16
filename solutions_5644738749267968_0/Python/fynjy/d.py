#!/usr/bin/python

import sys;
import os.path; 

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def trace(x):
    #print x;
    pass;


def honest(naomi, ken):
    trace("HONEST:");
    n = 0;
    k = 0;
    score = 0;
    while n < len(naomi):
        trace("naomi %d %g" % (n, naomi[n]));
        while k < len(ken) and naomi[n] >= ken[k]:
            trace("score+1, %d %g" % (k, ken[k]));
            k += 1;
            score += 1;
        if k >= len(ken):
            break
        n += 1;
        k += 1;
    return score;

def deceitful(naomi, ken):
    return len(naomi) - honest(ken, naomi);
    #trace("DECEITFUL:");
    ##kensSmallest = ken[0];
    #k = 0;
    #score = len(naomi);
    #n = 0;
    #while n < len(naomi):
    #    while n < len(naomi) and and naomi[n] < ken[k]:
    #        n += 1;
    #        score -= 1;

    #    if n >= len(naomi):
    #        break;

    #    n += 1;
    #    k += 1;

    #return score;

def main():
    nt = readi();
    for t in range(1, nt+1):
        trace("");
        N = readi();
        naomi = sorted(readfa());
        ken = sorted(readfa());
        trace(" ".join(str(x) for x in naomi));
        trace(" ".join(str(x) for x in ken));
        honestScore = honest(naomi, ken);
        deceitfulScore = deceitful(naomi, ken);
        print "Case #%d: %d %d" % (t, deceitfulScore, honestScore);
    

main();
