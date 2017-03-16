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

inputFile = "A-small-attempt1.in"

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
    case = line;
    return case

def getCaseOutput(case):
    val = doCase(case)
    return str(val)

def doCase(stuff):
    digits = [];

    print stuff

    while "Z" in stuff: # zero
        stuff = stuff.replace('Z','', 1)
        stuff = stuff.replace('E','', 1)
        stuff = stuff.replace('R','', 1)
        stuff = stuff.replace('O','', 1)
        digits.append('0');

    while "W" in stuff: # two
        stuff = stuff.replace('T','', 1)
        stuff = stuff.replace('W','', 1)
        stuff = stuff.replace('O','', 1)
        digits.append('2');
        
    while "X" in stuff: # six
        stuff = stuff.replace('S','', 1)
        stuff = stuff.replace('I','', 1)
        stuff = stuff.replace('X','', 1)
        digits.append('6');

    while "G" in stuff: # eight
        stuff = stuff.replace('E','', 1)
        stuff = stuff.replace('I','', 1)
        stuff = stuff.replace('G','', 1)
        stuff = stuff.replace('H','', 1)
        stuff = stuff.replace('T','', 1)
        digits.append('8');
    
    while "T" in stuff: # three
        stuff = stuff.replace('T','', 1)
        stuff = stuff.replace('H','', 1)
        stuff = stuff.replace('R','', 1)
        stuff = stuff.replace('E','', 1)
        stuff = stuff.replace('E','', 1)
        digits.append('3');

    while "R" in stuff: # four
        stuff = stuff.replace('F','', 1)
        stuff = stuff.replace('O','', 1)
        stuff = stuff.replace('U','', 1)
        stuff = stuff.replace('R','', 1)
        digits.append('4');

    while "F" in stuff: # five
        stuff = stuff.replace('F','', 1)
        stuff = stuff.replace('I','', 1)
        stuff = stuff.replace('V','', 1)
        stuff = stuff.replace('E','', 1)
        digits.append('5');

    while "O" in stuff: 
        stuff = stuff.replace('O','', 1)
        stuff = stuff.replace('N','', 1)
        stuff = stuff.replace('E','', 1)
        digits.append('1');

    while "V" in stuff:
        stuff = stuff.replace('S','', 1)
        stuff = stuff.replace('E','', 1)
        stuff = stuff.replace('V','', 1)
        stuff = stuff.replace('E','', 1)
        stuff = stuff.replace('N','', 1)
        digits.append('7');

    while "N" in stuff: 
        stuff = stuff.replace('N','', 1)
        stuff = stuff.replace('I','', 1)
        stuff = stuff.replace('N','', 1)
        stuff = stuff.replace('E','', 1)
        digits.append('9');

    digits = sorted(digits)
        
    return ''.join(digits);
    
runSolution(inputFile)
