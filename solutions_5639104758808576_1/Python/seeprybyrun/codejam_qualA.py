#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
import time

def solve(sMax,numShy,whichCase):
    # assume all invited friends have shyness level 0
    
    # if exists anyone with shyness level 1:
    #   if number of shyness level 0 is smaller than 1:
    #     add enough friends to level 0 to bring it to 1

    # if exists anyone with shyness level 2:
    #   if number of shyness levels 0+1 is smaller than 2:
    #     add enough friends to level 0 to bring it to 2
    numFriends = 0
    peopleStandingUpAlready = numShy[0]
    for k in range(1,sMax+1):
        if numShy[k] > 0 and peopleStandingUpAlready < k:
            numFriends += k - peopleStandingUpAlready
            peopleStandingUpAlready = k + numShy[k]
        else:
            peopleStandingUpAlready += numShy[k]
    return 'Case #{}: {}'.format(whichCase,numFriends)

T = 0 # number of test cases
sMax = 0 # max shyness
numShy = [] # number of people of each shyness level
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
    # first line of each test case tells us C
    else:
        sMax,numShy = line.split()
        sMax = int(sMax)
        numShy = [ int(d) for d in numShy ]
        print solve(sMax,numShy,whichCase)
        whichCase += 1

t1 = time.clock()
f.close()
#print "seconds elapsed: {0}".format(t1-t0)
