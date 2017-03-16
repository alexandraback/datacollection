import math
import random

def gen_primes():
    """ Generate an infinite sequence of prime numbers.
    """
    # Maps composites to primes witnessing their compositeness.
    # This is memory efficient, as the sieve is not "run forward"
    # indefinitely, but only as long as required by the current
    # number being tested.
    #
    D = {}
    
    # The running integer that's checked for primeness
    q = 2
    
    while True:
        if q not in D:
            # q is a new prime.
            # Yield it and mark its first multiple that isn't
            # already marked in previous iterations
            # 
            yield q
            D[q * q] = [q]
        else:
            # q is composite. D[q] is the list of primes that
            # divide it. Since we've reached q, we no longer
            # need it in the map, but we'll mark the next 
            # multiples of its witnesses to prepare for larger
            # numbers
            # 
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        
        q += 1


def gen_digits(nDigit):

    listDigit = [1]
    for iDigit in range(1, nDigit-1):

        listDigit.append(random.randint(0, 1))

    listDigit.append(1)

    return listDigit


def convert_string(listDigit, listFactor):

    strDigit = ''
    for iDigit in range(0, len(listDigit)):

        strDigit = strDigit + str(listDigit[iDigit])

    strFactor = ''
    for iFactor in range(0, len(listFactor)):

        strFactor = strFactor + ' ' + str(listFactor[iFactor])

    return strDigit + strFactor + '\n'


def convert_decimal(listDigit, baseNum):

    nDigit = len(listDigit)

    decimal = 0
    for iDigit in range(0, nDigit):

        decimal = decimal + listDigit[iDigit]*(baseNum**(nDigit - iDigit - 1))

    return decimal


def find_factor(decimal, listPrime):

    for iPrime in range(0, len(listPrime)):

        if decimal <= listPrime[iPrime]:

            return 1

        if decimal % listPrime[iPrime] == 0:

            return listPrime[iPrime]

    return 1

fhIn  = open('input_test',  'r')
fhOut = open('output', 'w') 

nCase = int(fhIn.readline())
for iCase in range(1, nCase+1):

    strCase   = str(fhIn.readline()).split(' ')
    numLen    = int(strCase[0])
    nSolution = int(strCase[1])

    print(str(numLen) + ' ' + str(nSolution) + '\n')

    strResult = format('Case #%d:\n' % iCase)
    fhOut.write(strResult)

    maxNum = int('1'*numLen)

    # Generate prime numbers
    nPrime    = 10**4
    genPrime  = gen_primes()
    listPrime = []
    for iPrime in range(0, nPrime):

        listPrime.append(genPrime.next())

    listSolution = []
    for iSolution in range(0, nSolution):

        while True:

            listFactor = []
            listDigit  = gen_digits(numLen)
            for iBase in range(2, 11):

                decimal = convert_decimal(listDigit, iBase)
                factor  = find_factor(decimal, listPrime)

                #print(str(decimal) + ': ' + str(factor))

                if factor == 1:

                    break

                else:

                    listFactor.append(factor)

            # Jamcoin found
            if len(listFactor) == 9:

                decimal = convert_decimal(listDigit, 10)
                if decimal in listSolution:
                    
                    continue

                else:

                    listSolution.append(decimal)

                    strResult = convert_string(listDigit, listFactor)
                    print(strResult)
                    fhOut.write(strResult)
                    break


fhIn.close()
fhOut.close()
