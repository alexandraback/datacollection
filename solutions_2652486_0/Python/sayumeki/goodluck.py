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

inputFile = "C-small-1-attempt0.in"

outputFile = "output.txt"
outFile = open(outputFile, mode='w')

def runSolution(inFile):
    
    lines = open(inFile, mode='r').readlines()
    ln = 0 #ln = line number
    
    cases = int(lines[ln])

    for i in range(0, len(lines)):
        lines[i] = lines[i].strip()
    ln += 1
    for i in range(0, cases):
        caseInput = lines[1:]
        #ln += 1 #skip blank line in input
        
        case = formatCaseInput(caseInput)

        print "Case #" + str(i+1) + ": " 
        outFile.write("Case #" + str(i+1) + ": "  + '\n')
        
        output = getCaseOutput(case)
        
        
        
    outFile.close()
        

def formatCaseInput(caseInput):
    line = caseInput[0].split(" ")
    for i in range(0, 4):
        line[i] = int(line[i])
    r = line[0]
    n = line[1]
    m = line[2]
    k = line[3]
    sets = []
    for i in range(0, r):
        setT = caseInput[1+i].split(" ")
        for j in range(0, k):
            setT[j] = int(setT[j])
        sets.append(setT)

    case = [n, m, sets]
    return case

def generateAllSets(numberCount, maxNumber):
    allSets = [
        [2,2,2],
        [2,2,3],
        [2,2,4],
        [2,2,5],
        [2,3,2],
        [2,3,3],
        [2,3,4],
        [2,3,5],
        [2,4,2],
        [2,4,3],
        [2,4,4],
        [2,4,5],
        [2,5,2],
        [2,5,3],
        [2,5,4],
        [2,5,5],
        [3,2,2],
        [3,2,3],
        [3,2,4],
        [3,2,5],
        [3,3,2],
        [3,3,3],
        [3,3,4],
        [3,3,5],
        [3,4,2],
        [3,4,3],
        [3,4,4],
        [3,4,5],
        [3,5,2],
        [3,5,3],
        [3,5,4],
        [3,5,5],
        [4,2,2],
        [4,2,3],
        [4,2,4],
        [4,2,5],
        [4,3,2],
        [4,3,3],
        [4,3,4],
        [4,3,5],
        [4,4,2],
        [4,4,3],
        [4,4,4],
        [4,4,5],
        [4,5,2],
        [4,5,3],
        [4,5,4],
        [4,5,5],
        [5,2,2],
        [5,2,3],
        [5,2,4],
        [5,2,5],
        [5,3,2],
        [5,3,3],
        [5,3,4],
        [5,3,5],
        [5,4,2],
        [5,4,3],
        [5,4,4],
        [5,4,5],
        [5,5,2],
        [5,5,3],
        [5,5,4],
        [5,5,5]]
    return allSets

def canMakeProduct(posSet, product):
    if product == 1:
        return True

    if len(posSet) == 0:
        return False

    if (product % posSet[0] == 0):
        return (canMakeProduct(posSet[1:], product) or
                canMakeProduct(posSet[1:], product / posSet[0]))

    else:
        return (canMakeProduct(posSet[1:], product))
    
def getCaseOutput(case):
    numberCount = case[0]
    maxNumber = case[1]

    for numSet in case[2]:
        print str(numSet) + " TARGET"
        allSets = generateAllSets(numberCount, maxNumber)
        possibleSets = []
        for posSet in allSets:
            #print str(posSet) + " CANDIDATE"
            canDo = True
            for product in numSet:
                if canMakeProduct(posSet, product) == False:
                    canDo = False
                else:
                    cool = True
                    #print str(posSet) + " CAN make " + str(product)
            if canDo:
                possibleSets.append(posSet)
        print possibleSets

        selectedSet = possibleSets[0]
        outstr = ""
        for num in selectedSet:
            outstr += str(num)
        print outstr
        outFile.write(outstr + '\n')
        
    return ""

runSolution(inputFile)
