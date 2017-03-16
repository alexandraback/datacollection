#!/usr/bin/python

import re
import bisect
import sys

def bruteForce(L, nbSpecialStep, bestNbStep) :
    if L[-1] <= nbSpecialStep :
        return bestNbStep;
    nbSpecialStep += 1;
    maxDiner = L[-1];
    LDiners2 = L[:-1];
    LDiners3 = L[:-1];
    
    bisect.insort(LDiners2, maxDiner//2);
    bisect.insort(LDiners2, maxDiner - maxDiner//2);
    if bestNbStep > LDiners2[-1] + nbSpecialStep :
        bestNbStep = LDiners2[-1] + nbSpecialStep;

    recBest = bruteForce(LDiners2, nbSpecialStep, bestNbStep);
    if recBest < bestNbStep :
        bestNbStep = recBest;
        
    bisect.insort(LDiners3, maxDiner//3);
    bisect.insort(LDiners3, maxDiner - maxDiner//3);
    if bestNbStep > LDiners3[-1] + nbSpecialStep :
        bestNbStep = LDiners3[-1] + nbSpecialStep;

    recBest = bruteForce(LDiners3, nbSpecialStep, bestNbStep);
    if recBest < bestNbStep :
        bestNbStep = recBest;

    return recBest;

f = open("B-small-attempt4.in", "r");
T = f.readline();
m = re.search('[0-9]*', T);
T = int(m.group(0));

reSplit = re.compile(" +");
reNumber = re.compile("[0-9]+");
reEachNumber = re.compile("[0-9]");

for case in range(T) :
    line = f.readline();
    D = reNumber.search(line).group(0);
    line = f.readline();
    LStrDiners = reSplit.split(line);
    LDiners = [];
    for strDiner in LStrDiners :
        LDiners.append(int(strDiner));
    LDiners.sort();
    
    nbStep = bruteForce(LDiners, 0, LDiners[-1]);
    
    print ("Case #" + str(case+1) + ": "+str(nbStep));
