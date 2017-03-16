from collections import Counter
from random import choice

def removeTooHigh(limit, possibleDivisors):
    remove = []
    for possible in possibleDivisors:
        if possible > limit:
            remove.append(possible)
    for i in remove:
        try:
            possibleDivisors.remove(i)
        except:
            pass
    return possibleDivisors

def divisors(n):
    divs = []
    sq = int(n ** 0.5)
    for factor in range(1, sq + 1):
        if n % factor == 0:
            divs.append(factor)
            other = n / factor
            if other != factor:
                divs.append(other)
    return divs

def getMostCommon(numberOfCommon, numbers):
    lst = []
    com = Counter(numbers).most_common(len(numbers))
    for tup in com:
        n = tup[0]
        if n != 1: lst.append(n)
    return lst

def concaten(nums):
    xs = ''
    for x in nums:
        xs += str(x)
    return xs

def solve(cases, inFile, outputFile):
    for c in xrange(1, cases + 1):
        outputFile.write("Case #" + str(c) + ":\n")
        line1 = inFile.readline().split()
        sets = int(line1[0]) # number of cardsets given each with
        numbers = int(line1[1]) # number cards each with a number
        limit = int(line1[2]) # from 2 to this number
        for cs in xrange(1, sets + 1):
            products = map(int, inFile.readline().split())
            print 'PRODUCTS', products
            allDivs = []
            for prod in products:
                for div in divisors(prod):
                    allDivs.append(div)
            possible = removeTooHigh(limit, getMostCommon(4, allDivs))
            for n in xrange(2, limit + 1):
                if not n in possible:
                    possible.append(n)
            print 'POSSIBLE', possible
            nums = []
            for i in xrange(1, numbers + 1):
                nums.append(choice(possible))
            ans = concaten(nums)
            print 'ANS', ans
            outputFile.write(str(ans) + '\n')

inFile = open('C-small-1-attempt2.in')
outputFile = open('output.txt', 'w')

cases = int(inFile.readline())
print cases, 'cases read'

solve(cases, inFile, outputFile)
print 'done'

inFile.close()
outputFile.close()