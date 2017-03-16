# -*- coding: utf-8 -*-

# just copy a whole bunch of these just in case
import time
import sys, traceback, ast
import fileinput
import os
import re
import httplib
import codecs
import HTMLParser
import math
import operator
import copy;

inputFile = "input.txt"
inputFile = "C-small-attempt1.in";

outputFile = "output3.txt"
outFile = open(outputFile, mode='w')

def runSolution(inFile):
    
    lines = open(inFile, mode='r').readlines()
    ln = 0 #ln = line number
    
    cases = int(lines[ln])
    ln += 1
    for i in range(0, cases):
        caseInput = []
        linesInCase = 1
        
        for j in range(0, linesInCase):
            caseInput.append(lines[ln].strip())
            ln += 1
        #ln += 1 #skip blank line in input
        
        case = formatCaseInput(caseInput)
        output = getCaseOutput(case)
        
        print "Case #" + str(i+1) + ": " + str(len(output))
        outFile.write("Case #" + str(i+1) + ": " + str(len(output)) + '\n')

        for outfit in output:
            outString = str(outfit[0]) + " " + str(outfit[1]) + " " + str(outfit[2]);
            print outString;
            outFile.write(outString + '\n');
        
    outFile.close()
        

def formatCaseInput(caseInput):
    line = caseInput[0]
    splitln = line.split(" ")
    x = int(splitln[0])
    r = int(splitln[1])
    c = int(splitln[2])
    c2 = int(splitln[3])

    case = []
    case.append(x)
    case.append(r)
    case.append(c)
    case.append(c2)
    #print case
    return case

def getCaseOutput(case):
    val = doCase(case)
    return val;

def getAllCombos(stuff):
    j = stuff[0];
    p = stuff[1];
    s = stuff[2];

    combos = []
    i = 0;
    while i < j:
        combos.append([i+1]);
        i += 1;

    i = 0; 
    newCombos = [];
    while i < p:
        for combo in combos:
            combo2 = copy.deepcopy(combo);
            combo2.append(i+1);
            newCombos.append(combo2);
        i += 1;
    combos = newCombos;

    i = 0; 
    newCombos = [];
    while i < s:
        for combo in combos:
            combo = copy.deepcopy(combo);
            combo.append(i+1);
            newCombos.append(combo);
        i += 1;
    combos = newCombos;

    return combos;

def isPoliceOk(outfits, k):
    violations = 0;
    violationDict = {};

    index = 0;
    while index < len(outfits):
        out1 = outfits[index];
        index2 = index + 1;
        while index2 < len(outfits):
            out2 = outfits[index2];
            violationCode = ""; # CHECK
            if (out1[0] == out2[0] and out1[1] == out2[1]):
                violationCode = str(out1[0]) + str(out1[1]) + "X"; 
            if (out1[0] == out2[0] and out1[2] == out2[2]):
                violationCode = str(out1[0]) + "X" + str(out1[2]); 
            if (out1[1] == out2[1] and out1[2] == out2[2]):
                violationCode = "X" + str(out1[1]) + str(out1[2]); 
            
            if len(violationCode) > 0:
                if violationCode not in violationDict:
                    violationDict[violationCode] = 1;
                else:
                    violationDict[violationCode] += 1;
                if violationDict[violationCode] >= k:
                    return 99;

            index2 += 1;
        index += 1;

    theMax = 0;
    for value in violationDict.values():
        if value > theMax:
            theMax = value;
    #print violationDict;

    return theMax;

def doCase(stuff):
    combos = getAllCombos(stuff);
    k = stuff[3];

    maxOutfits = [];

    i = 0;
    theMax = pow(2, len(combos)); # can get big

    if theMax == pow(2, len(combos)):
        if k == 1:
            return [[1,1,1],[1,2,2],[1,3,3],[2,1,2],[2,2,3],[3,2,1],[3,3,3]];
        else:
            return combos;

    while i < theMax:
        binaryString = bin(i)[2:].zfill(len(combos));
        #binaryString = binaryString[::-1];
        #print binaryString;

        if binaryString.count('1') <= len(maxOutfits):
            i += 1;
            continue;

        outfits = [];
        index = 0;
        while index < len(combos):
            if binaryString[index] == '1':
                outfits.append(combos[index]);
            index += 1;
        
        if len(outfits) > len(maxOutfits):
            vio = isPoliceOk(outfits, k);
            #print str(k) + " " + str(outfits);
            if vio < k: # police check
                maxOutfits = outfits;
            else:
                okssss = 1;
                #print str(k) + " " + str(outfits);

        i += 1;

    print maxOutfits;
    return maxOutfits;
    
runSolution(inputFile)
