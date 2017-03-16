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

inputFile = "B-small-attempt0.in"

outputFile = "output.txt"
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
        
        print "Case #" + str(i+1) + ": " + output
        outFile.write("Case #" + str(i+1) + ": " + output + '\n')
        
    outFile.close()
        

def formatCaseInput(caseInput):
    line = caseInput[0]
    splitln = line.split(" ")
    case = [splitln[0], splitln[1]];
    return case

def getCaseOutput(case):
    val = doCase(case)
    return str(val)

def generateAllMatchingScores(stuff):
    score1 = stuff[0];
    score2 = stuff[1];
    totalScore = str(score1) + " " + str(score2);

    vScores = [];
    
    questionMarks = score1.count('?') + score2.count('?');
    
    maxValue = math.pow(10, questionMarks);
    questionValue = 0;
    while questionValue < maxValue:
        qString = str(questionValue).zfill(questionMarks);

        newT = totalScore;
        for char in qString:
            newT = newT.replace('?', char, 1);

        newS = newT.split(' ');
        newS = [int(newS[0]), int(newS[1])];
        
        vScores.append(newS);
        
        questionValue += 1;

    return vScores;

def doCase(stuff):
    digits = [];

    scores = generateAllMatchingScores(stuff);

    minDiff = -1;
    minScores = -1;
    win = None
    
    for scorePair in scores:
        diff = abs(scorePair[0] - scorePair[1]);
        total = scorePair[0] + scorePair[1];
        if (minDiff == -1 or diff < minDiff):
            minDiff = diff;
            minScores = total;
            win = scorePair;
        elif (diff == minDiff):
            if (minScores == -1 or total < minScores):
                minDiff = diff;
                minScores = total;
                win = scorePair;

    return str(win[0]).zfill(len(str(stuff[0]))) + " " + str(win[1]).zfill(len(str(stuff[1])));
    
runSolution(inputFile)
