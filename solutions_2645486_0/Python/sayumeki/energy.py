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
        linesInCase = 2
        
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
    energy = int(splitln[0])
    recover = int(splitln[1])
    active = int(splitln[2])

    line = caseInput[1]
    splitln = line.split(" ")
    for i in range(0, active):
        splitln[i] = int(splitln[i])

    case = []
    case.append(energy)
    case.append(recover)
    case.append(splitln)
    #print case
    return case

def getCaseOutput(case):
    val = doCase(case[0], case[1], case[2], case[0])
    return str(val)

def doCase(energy, recover, activities, maxEnergy):
    if (energy > maxEnergy):
        energy = maxEnergy
        
    if (len(activities) == 0):
        return 0

    else:
        maxValue = 0
        restAct = activities[1:]
        for i in range(0, energy+1):
            score = (activities[0] * i) + doCase(energy - i + recover, recover, restAct, maxEnergy)
            if (score > maxValue):
                maxValue = score
        return maxValue
    
runSolution(inputFile)
