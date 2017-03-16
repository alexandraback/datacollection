#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
import time
import copy

def solve(numPancakes):

    def splitMaxes(numPancakes):
        M = max(numPancakes)
        numMaxes = numPancakes.count(M)
        if M % 2 == 0: # if M is even, do an even split
            return [p if p != M else M/2 for p in numPancakes] + ([M/2]*numMaxes)
        else: # otherwise, split into (M+1)/2 and (M-1)/2
            return [p if p != M else (M+1)/2 for p in numPancakes] + ([(M-1)/2]*numMaxes)
    
    numMinutes = 0
    initMax = max(numPancakes)
    # new strategy:
    # Count the number of Ms. If there are fewer than M/2 instances (for M
    # even) or fewer than (M-1)/2 instances (for M odd) of Ms, then it is
    # worthwhile to split all the Ms. Otherwise it is not worthwhile to split
    # any, since you only get the time benefit if you split all of them.
    for t in range(initMax):
        #print numPancakes
        M = max(numPancakes)
        numMaxes = numPancakes.count(M)
        if (M%2==0 and numMaxes<M/2) or (M%2==1 and numMaxes<(M-1)/2):
            numPancakes = splitMaxes(numPancakes)
            numMinutes += numMaxes
        else:
            numPancakes = [p-1 for p in numPancakes if p > 1]
            numMinutes += 1

        # stop early if all pancakes are gone
        if not numPancakes:
            break
    return numMinutes

T = 0 # number of test cases - can ignore this
numDiners = 0 # number of diners - can ignore this
numPancakes = [] # number of pancakes on each diner's plate initially
whichCase = 1

# read input
infile = sys.argv[1] #input("Enter the file name: ")
f = open(infile,'r')

t0 = time.clock()

for i,line in enumerate(f.readlines()):
#    print i,line
    line = line.strip()
    if not line:
        break
    
    # first line tells us T
    if i == 0:
        T = int(line)
    # after that, lines 1,3,5,... tell us # of diners
    # (this value can be ignored since it can be inferred from the length
    # of numPancakes)
    elif i % 2 == 1:
        numDiners = int(line)
    # and lines 2,4,6,... tell us initial pancake values
    elif i % 2 == 0:
        numPancakes = [ int(p) for p in line.split() ]
        print 'Case #{}: {}'.format(whichCase,solve(numPancakes))
        whichCase += 1

t1 = time.clock()
f.close()
#print "seconds elapsed: {0}".format(t1-t0)
