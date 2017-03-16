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

inputFile = "B-large.in"

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

    score1 = stuff[0];
    score2 = stuff[1];
    index = 0;
    print stuff;
    while index < len(score1) and (score1[index] == '?' or score2[index] == '?' or score1[index] == score2[index]):
        if (score1[index] == '?' and score2[index] == '?'):
            score1 = score1.replace('?', '0', 1); 
            score2 = score2.replace('?', '0', 1); 
        elif (score1[index] == '?'):
            score1 = score1.replace('?', score2[index], 1); 
        elif (score2[index] == '?'):
            score2 = score2.replace('?', score1[index], 1);
        index += 1;

    if score1.count('?') > 0 or score2.count('?') > 0:
        index -= 0;
        if index < 0:
            index = 0;
        if (score1[index] < score2[index]):
            score1 = score1.replace('?', '9'); 
            score2 = score2.replace('?', '0');
        else:
            score1 = score1.replace('?', '0'); 
            score2 = score2.replace('?', '9')

    return score1.zfill(len(stuff[0])) + " " + score2.zfill(len(stuff[0])) ;
runSolution(inputFile)
