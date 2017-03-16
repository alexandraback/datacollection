'''
Created on Apr 12, 2013

@author: user

compute once, then binary search
'''

import sys, math, bisect

def isPalindrome(num):
    return str(num) == str(num)[::-1]

def fairSquareRoots(lower, upper):
    ''' list of roots of fair squares between lower and upper inclusive'''

    # smallest root
    lowerRt = math.ceil(math.sqrt(lower))
    # largest root
    upperRt = math.floor(math.sqrt(upper))
    
    result = []

    for i in range(lowerRt, upperRt + 1):
        if isPalindrome(i) and isPalindrome(i * i):
            result.append(i)
    
    return result

def fairSquaresInBounds(lower, upper, allRoots):
    # smallest root
    lowerRt = math.ceil(math.sqrt(lower))
    # largest root
    upperRt = math.floor(math.sqrt(upper))
    
    idxL = bisect.bisect_left(allRoots, lowerRt)
    idxR = bisect.bisect_right(allRoots, upperRt)

    return idxR - idxL 


def processFile(fileName):
    
    maxBound = 1
    boundsList = []

    with open(fileName) as handle:
        trials = int(handle.readline().strip())
        for i in range(trials):
            bounds = [int(x) for x in handle.readline().strip().split(' ')]
            boundsList.append(bounds)
            maxBound = max(bounds[1], maxBound)
    
    allFairSqrts = fairSquareRoots(1, maxBound)
    
    results = []
    for bounds in boundsList:
        results.append(fairSquaresInBounds(bounds[0], bounds[1], allFairSqrts))

    return results
   
   
def writeResults(results, fileName):
    with open(fileName, 'w') as handle:
        case = 1
        
        for result in results:
            handle.write('Case #{}: {}\n'.format(case, result))
            case += 1
            

def main():
    results = processFile(sys.argv[1])
    writeResults(results, sys.argv[2])

if __name__ == '__main__':
    main()
