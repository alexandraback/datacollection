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
import copy
import pprint

inputFile = "C-small-attempt2.in"
#inputFile = "input.txt"

outputFile = "output.txt"
outFile = open(outputFile, mode='w')

def runSolution(inFile):
    
    lines = open(inFile, mode='r').readlines()
    ln = 0 #ln = line number
    
    cases = int(lines[ln])
    ln += 1
    for i in range(0, cases):
        caseInput = []
        linesInCase = int(lines[ln])
        ln += 1;
        
        for j in range(0, linesInCase):
            caseInput.append(lines[ln].strip())
            ln += 1
        #ln += 1 #skip blank line in input
        
        case = formatCaseInput(caseInput)
        output = getCaseOutput(case)
        
        print "Case #" + str(i+1) + ": " + output
        outFile.write("Case #" + str(i+1) + ": " + output + '\n')
        
    outFile.close()
        

def formatCaseInput(caseInput):
    case = [];
    for thing in caseInput:
        case.append(thing.split(" "));

    return case

def getCaseOutput(case):
    val = doCase(case)
    return str(val)

'''def doCase(stuff):
    frontWords = [];
    backWords = [];

    for words in stuff:
        frontWords.append(words[0]);
        backWords.append(words[1]);

    frontWords = list(set(frontWords));
    backWords = list(set(backWords));
    topicCount = len(stuff);
    
    print frontWords;
    print backWords;
    
    fakes = 0;
    frontCount = len(frontWords);
    backCount = len(backWords);
    ok = max(frontCount, backCount);
 
    return str(topicCount - ok);'''

def generateAllBinaryStringsOfLength(count):
    strs = ['0', '1'];
    loops = 1;
    while loops < count:
        newStrs = [];
        for thing in strs:
            newStrs.append(thing + '0');
            newStrs.append(thing + '1');
        strs = newStrs;
        loops += 1;
    return strs;

def setIsLegit(theSet):
    setWithout = theSet;

    foundTest = False;
    if ['SCHEDULING', 'EQUILIBRIA'] in theSet:
        foundTest = True;
        
    for entry in theSet:
        #setWithout = copy.deepcopy(theSet);
        #setWithout.remove(entry);

        frontFound = False;
        backFound = False;
        for other in setWithout:
            if entry[0] == other[0] and entry[1] == other[1]:
                continue;
            if entry[0] == other[0]:
                frontFound = True;
            if entry[1] == other[1]:
                backFound = True;

        if frontFound and backFound:
            return False;
        
    return True;
    
def doCase(stuff): # brute force lol
    longestSet = 0;
    best = None;
    #pprint.pprint(stuff)
    
    binaries = generateAllBinaryStringsOfLength(len(stuff));
    for binary in binaries:
        fakeCount = binary.count('1');

        fakes = [];
        notFakes = [];

        index = 0;
        for char in binary:
            if char == '1':
                fakes.append(stuff[index]);
            if char == '0':
                notFakes.append(stuff[index]);
            index += 1;

        valid = True;
        for fake in fakes:
            frontFound = False;
            backFound = False;
            for other in notFakes:
                if fake[0] == other[0]:
                    frontFound = True;
                if fake[1] == other[1]:
                    backFound = True;
            if frontFound == False or backFound == False:
                valid = False;

        if valid and longestSet < fakeCount:
            longestSet = fakeCount;

    #pprint.pprint(best);
    return str(longestSet); 
    
runSolution(inputFile)
