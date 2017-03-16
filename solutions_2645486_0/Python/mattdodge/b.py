'''
Created on Apr 26, 2013

@author: Matt Dodge
'''

inFile = open('B-small-attempt4.in','r+')
#inFile = open('B-sample.in','r+')
outFile = open('B-small4.out','w')
#outFile = 'stdout'

def output(st):
    if outFile == 'stdout':
        print st
    else:
        outFile.write(st)
    
def nextRow(E,R,prevRow,val):
    vals = []
    
    # gonna leave myself i
    for i in range(0, len(prevRow)):
        curMax = 0
        
        # j was left before
        for j in range(0, len(prevRow)):
            prevVal = prevRow[j]
            curMax = max(curMax, prevVal + (min(E, R + j) - i) * val)
        vals.append(curMax)
        
    return vals
    
if __name__ == '__main__':
    numCases = int(inFile.readline().rstrip('\n'))
    
    for case in range(1, numCases+1):
        [E,R,N] = [int(x) for x in inFile.readline().rstrip('\n').split(' ')]
        
        v = [int(x) for x in inFile.readline().rstrip('\n').split(' ')]
        
        R = min(R,E)
        
        curRow = []
        for i in range(0,len(v)):
            val = v[i]
            if i == 0:
                curRow = [(val * e) for e in range(E, -1, -1)]
            else:
                curRow = nextRow(E, R, curRow, val)
                
            print curRow

        output('Case #{0}: {1}\n'.format(case,curRow[0]))
    
