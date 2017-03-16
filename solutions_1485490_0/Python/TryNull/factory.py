#!/usr/bin/python

import sys
import time

## Start here ##
from Classes import ProductionLine
from Classes import Interval
from symbol import classdef

##Helpers

def calculateWasteTillType(productionLine, type):
    sum = 0;
    for interval in productionLine.intervals:
        if interval.boxType == type:
            return sum
        sum = sum + interval.numberOfBoxes;
    return sum;
##

numberOfTestCases = int(sys.stdin.readline())

for testCaseNumber in range(numberOfTestCases):
    assemblyLines = sys.stdin.readline().strip()
    assemblyLines = assemblyLines.split(" ");
    
    lines = []
    for assembly in assemblyLines:
        productionLine = ProductionLine()
        productionLine.intervals = []
        
        intervals = sys.stdin.readline().strip()
        intervals = intervals.split(" ");
#        print intervals
        
        while len(intervals) > 0:
            interval = Interval()
            interval.numberOfBoxes = int(intervals.pop(0));
            interval.boxType = intervals.pop(0);
#            print "%s %s" % (interval.numberOfBoxes, interval.boxType)
            productionLine.intervals.append(interval)
        
#        print "Production line %s has %d intervals" % (assembly, len(productionLine.intervals))
        lines.append(productionLine)
    #print lines
    
    boxes = lines[0];
    toys = lines[1];
    
    boxedToys = 0
    while len(boxes.intervals) > 0 and len(toys.intervals) > 0:
        #print "Loop"
        currentBoxInterval = boxes.intervals[0];
        currentToyInterval = toys.intervals[0];
        
        #print "STATUS: b-%s t-%s"%(currentBoxInterval.numberOfBoxes, currentToyInterval.numberOfBoxes)
        if currentBoxInterval.boxType == currentToyInterval.boxType:
            currentBatch = min(currentBoxInterval.numberOfBoxes,currentToyInterval.numberOfBoxes)
            boxedToys = boxedToys + currentBatch
            currentBoxInterval.numberOfBoxes = currentBoxInterval.numberOfBoxes - currentBatch
            currentToyInterval.numberOfBoxes = currentToyInterval.numberOfBoxes - currentBatch
        else:
            boxWaste = calculateWasteTillType(boxes, currentToyInterval.boxType)
            toyWaste = calculateWasteTillType(toys, currentBoxInterval.boxType)
            #print "Waste: b-%s t-%s"%(boxWaste, toyWaste)
            if boxWaste > toyWaste:
                currentToyInterval.numberOfBoxes = 0
            else:
                currentBoxInterval.numberOfBoxes = 0

        #print "B %s %s %s" % (currentSession, currentBoxInterval.numberOfBoxes, currentToyInterval.numberOfBoxes)
        #print "A %s %s" % (currentBoxInterval.numberOfBoxes, currentToyInterval.numberOfBoxes)
        if currentBoxInterval.numberOfBoxes == 0:
            boxes.intervals.pop(0)
        if currentToyInterval.numberOfBoxes == 0:
            toys.intervals.pop(0)
        
        #time.sleep (1)
    
#    for classNumber in range(numberOfClasses):
#        #print classNumber;
#        classParents = sys.stdin.readline().strip()
#        classParents = classParents.split(" ");
#        numberOfParents = classParents.pop(0);
#
#        classDef = ClassDefinition()
#        classDef.name = str(classNumber+1) #for index lookup as string
#        classDef.numberOfParents = numberOfParents
#        classDef.parents = classParents
#        
#        classes[classDef.name] = classDef
##        print "%s parents %s"%(numberOfParents, classParents)

    ## at this point we know what the class tree looks like
    print "Case #%d: %d" % (testCaseNumber+1, boxedToys)
    ## only look at classes with 2 or more parents.

############ END ############
        