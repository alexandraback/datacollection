# Problem C: Fair and Square
# See how many square and palindromic numbers on an interval [a,b]
# Fair and square: both it and its square root are palindromes

from math import floor, ceil, sqrt

inputFile = open('C-large-1.in','rU')
outputFile = open('C-large-1.out','w')

# do stuff here
# METHOD 1: just brute force

def isPalindrome(number):
    components = str(number)
    length = len(components)
    for x in xrange(length / 2): # (e.g. 5/2 = 2, 6/2 = 3)
        if components[x] != components[-x - 1]:
            return False
    return True

def generatePally(digits):
    if digits == 1: # special evil
        return range(1, 10)

    palindromes = []
    lower = int(10 ** (digits / 2 - 1))
    higher = 10 ** (digits / 2)
##    print "lower = %d, higher = %d" % (lower, higher)
##    print "sum = %d" % len(xrange(lower,higher))
    for x in xrange(lower, higher): #e.g. 10->99, 1->9, etc
        string = str(x)
        if digits % 2 == 1:
            for y in xrange(10):
                palindromes.append(int(string + str(y) + string[::-1]))
        else:
            string += string[::-1]
            palindromes.append(int(string))
    return palindromes

# LARGE METHOD:
fairSquares = []
fairSquaresROOTS = []
palindromes = []
##cats = set() # debug
##dogs = set()
# for interval [1, 10 ** 50], how to does?
for digits in xrange(1, 8): # interval [1, 10 ** 7]
    palindromes += generatePally(digits)
for pally in palindromes:
    square = pally ** 2
##    cats.add(pally)
    if isPalindrome(square):
        fairSquares.append(square)
        fairSquaresROOTS.append(pally)
##        dogs.add(square)

##fairSquares = sorted(fairSquares) # low cost for [1,10**7]
##fairSquaresROOTS = sorted(fairSquaresROOTS)

#DEBUG
for number in palindromes:
    if isPalindrome(number) is False:
        raise("You failed on %d" % number)


cases = int(inputFile.readline())
for currentCase in xrange(1, cases + 1):
    A, B = map(int, inputFile.readline().strip().split())
    for x in fairSquares:
        if x >= A:
            lower = fairSquares.index(x) # small, not that slow
            break
    for y in fairSquares[::-1]:
        if y <= B:
            upper = fairSquares.index(y)
            break
    if lower > upper:
        result = 0
    else:
        result = upper - lower + 1
##    print "Case #%d: %d" % (currentCase, result)
    outputFile.write("Case #%d: %d\n" % (currentCase, result))
    

# HOLY ONLY 40 FAIRSQUARES CAN JUST BRUTE FORCE LOL


# this stuff must be pre-generated
##squares = map(lambda x: x ** 2, xrange(1,32))
##fairSquares = []
##for x in xrange(1, int(floor(sqrt(1000))) + 1):
##    if isPalindrome(x):
##        square = x ** 2
##        if isPalindrome(square):
##            fairSquares.append(square)
##
##cases = int(inputFile.readline())
##for currentCase in xrange(1, cases + 1):
##    A, B = map(int, inputFile.readline().strip().split())
##    totalPalindromes = 0
##    for x in xrange(A, B + 1):
##        if isPalindrome(x):
##            root = sqrt(x)
##            if root % 1 == 0:
##                if isPalindrome(int(root)):
##                    totalPalindromes += 1
##                    print "%d is a palindrome" % x
##    print "Case #%d: %d" % (currentCase, totalPalindromes)
##    outputFile.write("Case #%d: %d\n" % (currentCase, totalPalindromes))

# LARGER TEST CASE METHOD
##for digits in xrange(3 + 1):
##    palindromes += generatePally(digits)
##for pally in palindromes:
##    square = pally ** 2
##    if isPalindrome(square):
##        fairSquares.append(square)


inputFile.close()
outputFile.close()
