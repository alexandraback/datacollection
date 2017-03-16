'''
Created on Apr 12, 2013

@author: Matt Dodge
'''

from math import sqrt

inFile = open('C-small-attempt0.in','r+')
outFile = open('C-small-attempt0.out','w')

def output(st):
    if outFile == 'stdout':
        print st
    else:
        outFile.write(st)

def extendPalindromes(curP):
    newPal = set()
    for pal in curP:
        for i in range(0, 10):
            newPal.add(str(i) + str(pal) + str(i))
            
    curP = curP.union(newPal)
    return curP

def buildPalindromes():
    p = set([str(i) for i in range(0,10)])
    p.add('')
    
    for numDigits in range(0,3):
        p = extendPalindromes(p)
    
    return [int(i) for i in p if len(i) > 0 and i[0] != '0']

def isPalindrome(i):
    return str(i) == (str(i)[::-1])

def getCount(fromNum, toNum, fairs):
    fromSqrt = sqrt(fromNum)
    toSqrt = sqrt(toNum)
    
    return len([x for x in fairs if x >= fromSqrt and x <= toSqrt])

if __name__ == '__main__':
#    [L,D,N] = inFile.readline().rstrip('\n').split(' ')
    pals = buildPalindromes()
    
    fairSquares = []
    
    for pal in pals:
        if isPalindrome(pow(pal,2)):
            fairSquares.append(pal)
    
    fairSquares.sort()
    
    numCases = int(inFile.readline().rstrip('\n'))
    
    for case in range(1, numCases + 1):
        [A,B] = [int(x) for x in inFile.readline().rstrip('\n').split(' ')]
        output("Case #{0}: {1}\n".format(case, getCount(A,B,fairSquares)))
        
    
