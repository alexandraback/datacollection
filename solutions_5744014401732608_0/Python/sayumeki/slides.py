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

inputFile = "B-small-attempt3.in"
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
        linesInCase = 1
        
        for j in range(0, linesInCase):
            caseInput.append(lines[ln].strip())
            ln += 1
        #ln += 1 #skip blank line in input
        
        case = formatCaseInput(caseInput)
        output = getCaseOutput(case)
        
        if output == ["IMPOSSIBLE"]:
            print "Case #" + str(i+1) + ": IMPOSSIBLE";
            outFile.write("Case #" + str(i+1) + ": IMPOSSIBLE" + '\n')
        else:
            print "Case #" + str(i+1) + ": POSSIBLE";
            outFile.write("Case #" + str(i+1) + ": POSSIBLE" + '\n')
            for line in output:
                print line;
                outFile.write(line + '\n');
        
    outFile.close()

def formatCaseInput(caseInput):
    line = caseInput[0]
    splitln = line.split(" ")
    b = int(splitln[0])
    m = int(splitln[1])

    case = []
    case.append(b)
    case.append(m)
    #print case
    return case

def getCaseOutput(case):
    val = doCase(case)
    return val;

def doWays(stuff):
    strings = ["1"];
    index = 0;
    while index < len(stuff)-1:
        newStr = [];
        for strin in strings:
            if int(strin[-1]) == index+1:
                index2 = 0;
                while index2 < len(stuff[index]):
                    if int(stuff[index][index2]) == 1:
                        newStr.append(strin + str(index2+1));
                    index2 += 1;
            else:
                newStr.append(strin);
        strings = newStr;

        index += 1;
    return strings;

def doCase(stuff):
    answers = [];
    i = 0;
    while i < 22:
        ok = [];
        j = 0;
        while j < 22: 
            ok.append(-1);
            j += 1;
        i += 1;
        answers.append(ok);

    answers[2][1] = ["01","00"];
    answers[3][1] = ["001","000","000"];
    answers[3][2] = ["011","001","000"];
    answers[4][1] = ["0001","0000","0000","0000"];
    answers[4][2] = ["0101","0001","0000","0000"];
    answers[4][3] = ["0111","0001","0001","0000"];
    answers[4][4] = ["0111","0011","0001","0000"];
    answers[5][1] = ["00001","00000","00000","00000","00000"];
    answers[5][2] = ["01001","00001","00000","00000","00000"];
    answers[5][3] = ["01101","00001","00001","00000","00000"];
    answers[5][4] = ["01111","00001","00001","00001","00000"];
    answers[5][5] = ["01111","00001","00011","00001","00000"];
    answers[5][6] = ["01111","00011","00011","00001","00000"];
    answers[5][7] = ["01110","00111","00011","00001","00000"];
    answers[5][8] = ["01111","00111","00011","00001","00000"];
    answers[6][1] = ["000001","000000","000000","000000","000000","000000"]
    answers[6][2] = ["010001","000001","000000","000000","000000","000000"]
    answers[6][3] = ["011001","000001","000001","000000","000000","000000"]
    answers[6][4] = ["011101","000001","000001","000001","000000","000000"]
    answers[6][5] = ["011111","000001","000001","000001","000001","000000"]
    answers[6][6] = ["011111","001001","000001","000001","000001","000000"]
    answers[6][7] = ["011111","001101","000001","000001","000001","000000"]
    answers[6][8] = ["011111","001111","000001","000001","000001","000000"]
    answers[6][9] = ["011110","001111","000101","000001","000001","000000"]
    answers[6][10] = ["011111","001111","000101","000001","000001","000000"]
    answers[6][11] = ["011110","001111","000111","000001","000001","000000"]
    answers[6][12] = ["011111","001111","000111","000001","000001","000000"]
    answers[6][13] = ["011010","001111","000111","000011","000001","000000"]
    answers[6][14] = ["011011","001111","000111","000011","000001","000000"]
    answers[6][15] = ["011110","001111","000111","000011","000001","000000"]
    answers[6][16] = ["011111","001111","000111","000011","000001","000000"]

    if (answers[stuff[0]][stuff[1]] == -1):
        return ["IMPOSSIBLE"];

    expected = stuff[1];
    ways = doWays(answers[stuff[0]][stuff[1]]);
    if (len(ways) != expected):
        print "WARNING";
        print str(len(ways));
        print stuff;
        print 0 /0;
    return answers[stuff[0]][stuff[1]];
    
runSolution(inputFile)
