import math

primes = []

def getFirstDivisor(number):
    for x in range(2,1000):
        if number % x == 0:
            return (True, x)
    return (False, 0)

def getProof(binary):
    divisors = []
    for x in range(2, 11):
        number = getNumber(binary, x)
        possible, divisor = getFirstDivisor(number)
        if not possible:
            return (False, [])
        divisors.append(divisor)
    return (True, divisors)

def printBases(binary):
    for x in range(2, 11):
        number = getNumber(binary, x)
        print number
    

def getNumber(binary, base):
    return int(binary, base)

def findCoins(size, needed):
    start = int(math.pow(2, size - 1)) + 1
    end = int(math.pow(2, size))
    proven = 0
    print "Case #1:"
    for x in range(start, end, 2):
        if proven == needed:
            #print "DONE"
            return
        binary = "{0:b}".format(x)
        possible, proof = getProof(binary)
        if possible:
            proven += 1
            divisorString = ' '.join([str(section) for section in proof])
            #printBases(binary)
            print("%s %s" % (binary, divisorString))
      #  else:
           # print binary

findCoins(16, 50)