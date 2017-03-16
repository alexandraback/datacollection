# Run with Python 3.2

import math, sys, time

input_filename = "Clarge.txt"

def nextSquare(x):
    """Returns lowest square number >= x"""
    return math.ceil(x**0.5)**2

def prevSquare(x):
    """Returns highest square number <= x"""
    return math.floor(x**0.5)**2

def checkInt(x):
    #assert x == int(x), "Not an integer"
    return int(x)

def isPalindrome(x):
    """Returns True if the number is a palindrome"""
    #return True
    x = str(checkInt(x))
    return x == x[::-1]

def countDigits(x):
    return len(str(checkInt(x)))

def reverseNumber(x):
    return int(str(x)[::-1])

def precalc(start, end):
    """Returns a list of palindromic numbers with palindromic squares
    where the squares are between start and end (inclusive)."""
    start = checkInt(nextSquare(start)**0.5)
    end = checkInt(prevSquare(end)**0.5)
    n = []
    if True:
        minDigits = countDigits(start)
        maxDigits = countDigits(end)
        for digits in range(minDigits, maxDigits+1):
            
            # Only iterate over the first ceil(digits/2) digits.
            # If the number is a palindrome, the rest can be determined from those.

            numIteratedDigits = math.ceil(digits/2)
            numFixedDigits = digits - numIteratedDigits
            iteratedDigitShift = 10 ** numFixedDigits
            
            for firstDigits in range(10**(numIteratedDigits-1), 10**numIteratedDigits):
                wholeNumber = firstDigits * iteratedDigitShift
                if (digits % 2) == 1:
                    if digits > 1:
                        wholeNumber += reverseNumber(firstDigits//10)
                else:
                    wholeNumber += reverseNumber(firstDigits)

                #assert isPalindrome(wholeNumber)
                if wholeNumber >= start and isPalindrome(wholeNumber**2) and wholeNumber <= end:
                    n += [wholeNumber]

    else:
        for k in range(start, end+1):
            if (k % 10000) == 0: print(k)
            if isPalindrome(k) and isPalindrome(k**2):
                n += [k]

    return n

def solve(start, end, precalcData):
    start = checkInt(nextSquare(start)**0.5)
    end = checkInt(prevSquare(end)**0.5)
    
    n = 0
    for k in precalcData:
        if k >= start and k <= end:
            n += 1
    return n

if True:
    pcStart = 1
    pcEnd = 10**14
    precalcData = precalc(pcStart, pcEnd)
    with open(input_filename, "r") as infile:
        with open("output.txt", "w") as sys.stdout:
            numCases = int(infile.readline())
            for case in range(1,numCases+1):
                start, end = infile.readline().replace("\n","").split(" ")
                start = int(start)
                end = int(end)
                if start < pcStart:
                    raise Exception("Did not precalculate numbers before "+str(pcStart))
                if end > pcEnd:
                    raise Exception("Did not precalculate numbers after "+str(pcStart))
                print("Case #%i: %i" % (case, solve(start, end, precalcData)))

else:
    itersPerTime = 10
    for i in range(10000//itersPerTime):
        stime = time.time()
        for k in range(itersPerTime):
            n = precalc(1, 10**14)
            print(k,n)
        etime = time.time()
        print(itersPerTime," iterations in ",etime-stime," seconds")


