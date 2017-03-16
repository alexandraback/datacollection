'''
Created on Apr 12, 2013

@author: user
'''

import sys
import numpy

def canMow(lawn):
    '''lawn is a numpy array.
    depressions, a position smaller than other positions in of both row and column, invalidate the lawn.'''
    
    nRow = lawn.shape[0]
    nCol = lawn.shape[1]
    
    colMaxes = numpy.amax(lawn, 0)
    rowMaxes = numpy.amax(lawn, 1)
    
    for i in range(0, nRow):
        for j in range(0, nCol):
            if lawn[i, j] < colMaxes[j] and lawn[i, j] < rowMaxes[i]:
                return False
    
    return True

def processFile(fileName):
    results = []
    
    with open(fileName) as handle:
        trials = int(handle.readline().strip())
        
        for i in range(trials):
            dim = [int(x) for x in handle.readline().strip().split(" ")]
            lawn = numpy.zeros(dim)
            for j in range(dim[0]):
                lawn[j, :] = [int(x) for x in handle.readline().strip().split(" ")]

            results.append(canMow(lawn))
            
    return results
   
   
def writeResults(results, fileName):
    with open(fileName, 'w') as handle:
        case = 1
        
        for result in results:
            handle.write('Case #{}: {}\n'.format(case, 'YES' if result else 'NO'))
            case += 1
            

def main():
    results = processFile(sys.argv[1])
    writeResults(results, sys.argv[2])

if __name__ == '__main__':
    main()
