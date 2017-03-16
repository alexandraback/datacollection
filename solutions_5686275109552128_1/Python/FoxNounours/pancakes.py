#!/usr/bin/python

import re
import bisect
import sys

def bruteForce(L, nbSpecialStep, bestNbStep) :
    if L[-1] <= nbSpecialStep :
        return bestNbStep;
    nbSpecialStep += 1;
    maxDiner = L[-1];
    L = L[:-1];

    if maxDiner % 3 == 0 and ( len(L) < 2 or (len(L) >= 1 and L[-1] <= maxDiner//3) or (len(L) >= 2 and L[-2] <= maxDiner//3) ) :
        L2 = L[:]
        div = 3
 #       sys.stderr.write(str(nbSpecialStep) + ": " +  str(L2) + ":" + str(maxDiner) + " / " + str(div) + "\n");
        bisect.insort(L2, maxDiner//div);
        bisect.insort(L2, maxDiner - maxDiner//div);
        if bestNbStep > L2[-1] + nbSpecialStep :
            bestNbStep = L2[-1] + nbSpecialStep;
        best3 = bruteForce(L2, nbSpecialStep, bestNbStep);
        if bestNbStep > best3 :
            bestNbStep = best3;
            
    div = 2
#    sys.stderr.write(str(nbSpecialStep) + ": " +  str(L) + ":" + str(maxDiner) + " / " + str(div) + "\n");
    bisect.insort(L, maxDiner//div);
    bisect.insort(L, maxDiner - maxDiner//div);
    if bestNbStep > L[-1] + nbSpecialStep :
        bestNbStep = L[-1] + nbSpecialStep;

    return bruteForce(L, nbSpecialStep, bestNbStep);

sys.setrecursionlimit(10000);
f = open("B-large.in", "r");
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
  #  sys.stderr.write("init" + str(case+1) + ": "+str(LDiners) + "\n");
    LDiners.sort();
    
    nbStep = bruteForce(LDiners, 0, LDiners[-1]);
    
    print ("Case #" + str(case+1) + ": "+str(nbStep));
  #  sys.stderr.write("Case #" + str(case+1) + ": "+str(nbStep) + "\n\n");
