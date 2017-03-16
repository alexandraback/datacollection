#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
import time
import copy

RICH = 'RICHARD'
GABE = 'GABRIEL'

def solve(X,R,C):
    # yay case analysis! (the below logic is only valid for the short
    # solution, where 1 <= X,R,C <= 4)
    
    if X == 1: # only one 1-omino, and Gabe can always fill in any grid
        return GABE
    
    elif X == 2: # Gabe can do it iff the grid has an even # of squares
        if (R*C)%2 == 0:
            return GABE
        else:
            return RICH
        
    elif X == 3:
        if (R*C)%3 != 0: # the # of squares has to be div by 3 for Gabe to
                         # have a chance
            return RICH
        elif R==1 or C==1: # if a dimension is 1, Rich picks the L-shaped
                           # 3-omino, which Gabe cannot use
            return RICH
        else: # otherwise Gabe can do it!
            return GABE

    elif X == 4:
        if R < 4 and C < 4: # in this case, Rich picks the 1x4 bar
            return RICH
        elif R == 1 or C == 1: # in this case, Rich can pick anything other
                               # than the 1x4 bar to win
            return RICH
        elif R*C == 8: # this will only happen if {R,C} = {2,4}; in this case,
                       # Rich picks the Z-shaped 4-omino to win
            return RICH
        else: # otherwise Gabe can do it!
            return GABE

T = 0 # number of test cases - can ignore this
X = 0
R = 0
C = 0
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
    else:
        X,R,C = map(int,line.split())
#        print '{},{},{}'.format(X,R,C),
        print 'Case #{}: {}'.format(whichCase,solve(X,R,C))
        whichCase += 1

t1 = time.clock()
f.close()
#print "seconds elapsed: {0}".format(t1-t0)
