'''
Created on Apr 12, 2013

@author: Matt Dodge
'''

from numpy import *

inFile = open('B-small-attempt0.in','r+')
outFile = open('B-small-attempt0.out','w')

def output(st):
    if outFile == 'stdout':
        print st
    else:
        outFile.write(st)
        
def updateLawn(l, i):
    
    # See if any are too low
    if (l < i).any():
        raise
    
    # first go through rows
    for row in range(0,l.shape[0]):
        if (floor(l[row]) == i).all():
            # this is our cut, add it
            l[row] = l[row] + 0.6
            
    # then columns
    for col in range(0,l.shape[1]):
        if (floor(l[:,col]) == i).all():
            # this is our cut, add it
            l[:,col] = l[:,col] + 0.6
            
    return l.round()
                    
def validLawn(l):
    for i in range(1, 3):
        try:
            l = updateLawn(l, i)
        except:
            return False
    
    return True

if __name__ == '__main__':
    numCases = int(inFile.readline().rstrip('\n'))
    
    for case in range(1, numCases + 1):
        [R,C] = [int(x) for x in inFile.readline().rstrip('\n').split(' ')]

        lawn = zeros((R,C))
        
        for row in range(0,R):
            lawn[row] = inFile.readline().rstrip('\n').split(' ')
        print case    
        output("Case #{0}: {1}\n".format(case, ("YES" if validLawn(lawn) else "NO")))
    
