'''
Created on Apr 12, 2013

@author: user
'''

import sys, math

def isPalindrome(num):
    return str(num) == str(num)[::-1]

def fairSquares(lower, upper):
    ''' number of fair squares between lower and upper inclusive'''

    # smallest root
    lowerRt = math.ceil(math.sqrt(lower))
    # largest root
    upperRt = math.floor(math.sqrt(upper))
    
    count = 0

    for i in range(lowerRt, upperRt + 1):
        if isPalindrome(i) and isPalindrome(i * i):
            count += 1
    
    return count

def processFile(fileName):
    results = []

    with open(fileName) as handle:
        trials = int(handle.readline().strip())
        for i in range(trials):
            bounds = [int(x) for x in handle.readline().strip().split(' ')]
            results.append(fairSquares(bounds[0], bounds[1]))    

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
