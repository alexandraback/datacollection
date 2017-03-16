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

inputFile = "A-small-attempt0.in"

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
        
        #print "Case #" + str(i+1) + ": " + output
        outFile.write("Case #" + str(i+1) + ": " + output + '\n')
        
    outFile.close()
        

def formatCaseInput(caseInput):
    #case = [['','','',''], ['','','',''], ['','','',''], ['','','','']]
    #for lineNum in range(0, len(caseInput)):
    #    line = caseInput[lineNum]
    #    for j in range(0, len(line)):
    #        case[lineNum][j] = line[j]

    line = caseInput[0]
    splitLines = line.split(" ")
    #print splitLines
    case = [splitLines[0], splitLines[1]]
    return case

def getCaseOutput(case):
    radius = long(case[0])
    outerRadius = radius+1
    paint = long(case[1])

    score = 0
    sumd = 0
    while paint > 0:
        innerArea = radius*radius
        outerArea = outerRadius*outerRadius
        paintIt = outerArea-innerArea

        sumd = sumd + paintIt
        #print sumd
        paint = paint - paintIt

        radius += 2
        outerRadius += 2
        if (paint >= 0):
            score += 1
    return str(score)
            
runSolution(inputFile)
