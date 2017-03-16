import sys
import math

primesSample = [2, 3, 5, 7, 11, 13, 17, 19]

def isPrimeSlow(number):
    if number == 2:
        return True
    elif number < 2 or number % 2 == 0:
        return False
    limit = int(math.sqrt(number)) + 1
    for div in range(2, limit):
        if number % div == 0:
            return False
    return True

def isPrime(number, primes):
    if number == 2:
        return True
    elif number < 2 or number % 2 == 0:
        return False
    limit = int(math.sqrt(number)) + 1
    for prime in primes:
        if prime > limit:
            return True
        elif number % prime == 0:
            return False
    if limit > primes[-1]:
        return None
        # return isPrimeSlow(number)
    return True

assert(isPrime(2, primesSample) == True)
assert(isPrime(1, primesSample) == False)
assert(isPrime(3, primesSample) == True)
assert(isPrime(17, primesSample) == True)
assert(isPrime(42, primesSample) == False)

def computePrimes(limit):
    primes = []
    for number in range(2, limit + 1):
        if isPrime(number, primes):
            primes.append(number)
    return primes

assert(computePrimes(5) == [2, 3, 5])
assert(computePrimes(2) == [2])
assert(computePrimes(20) == primesSample)

def coinToBase(number, base):
    length, result = len(number), 0
    for index in range(0, length):
        if number[length - index - 1] == '1':
            result += (base ** index)
    return result

assert(coinToBase('110111', 3) == 337)
assert(coinToBase('1001', 2) == 9)
assert(coinToBase('1001', 3) == 28)
assert(coinToBase('1001', 4) == 65)
assert(coinToBase('1001', 5) == 126)
assert(coinToBase('1001', 6) == 217)
assert(coinToBase('1001', 7) == 344)
assert(coinToBase('1001', 8) == 513)
assert(coinToBase('1001', 9) == 730)
assert(coinToBase('1001', 10) == 1001)

def bin2dec(number):
    # returns int
    return int(number, 2)

assert(bin2dec('11') == 3)
assert(bin2dec('101') == 5)

def dec2bin(number):
    # returns str
    return bin(number)[2:]

assert(dec2bin(3) == '11')
assert(dec2bin(5) == '101')

def findDiv(number, primes):
    for prime in primes:
        if number % prime == 0:
            return prime
    # for div in range(primes[-1], int(math.sqrt(number)) + 1):
    #     if number % div == 0:
    #         return div
    return None

assert(findDiv(9, primesSample) == 3)
assert(findDiv(28, primesSample) == 2)
assert(findDiv(65, primesSample) == 5)
assert(findDiv(217, primesSample) == 7)

def prefill(string, char, length):
    return (char * length) + string

assert(prefill('', '0', -2) == '')
assert(prefill('', '0', 1) == '0')
assert(prefill('1001', '0', 2) == '001001')

def createCoin(length):
    return '1' + ('0' * (length - 2)) + '1'

assert(createCoin(2) == '11')
assert(createCoin(3) == '101')
assert(createCoin(4) == '1001')

def getNextCoin(number, length):
    base10 = bin2dec(number[1:-1]) + 1
    base2 = dec2bin(base10)
    fillLength = max(0, length - len(base2) - 2)
    return '1' + prefill(base2, '0', fillLength) + '1'

assert(getNextCoin('101', 3) == '111')
assert(getNextCoin('1001', 4) == '1011')
assert(getNextCoin('1011', 4) == '1101')

def coinToBases(coin):
    bases = []
    for base in range(2, 11):
        bases.append(coinToBase(coin, base))
    return bases

assert(coinToBases('1001') == [9, 28, 65, 126, 217, 344, 513, 730, 1001])

def hasPrime(numbers, primes):
    for number in numbers:
        if isPrime(number, primes) != False:
            return True
    return False

assert(hasPrime([1, 4, 9], primesSample) == False)
assert(hasPrime([1, 2, 3], primesSample) == True)
assert(hasPrime([2, 3, 17], primesSample) == True)

def findDivs(numbers, primes):
    divs = []
    for number in numbers:
        div = findDiv(number, primes)
        if div is None:
            return None
        else:
            divs.append(str(div))
    return divs

def findCoins(length, nb, primes):
    coin = createCoin(length)
    results = []
    while len(results) < nb:
        bases = coinToBases(coin)
        # print('Trying', coin, bases, file=sys.stderr)
        if not hasPrime(bases, primes):
            divs = findDivs(bases, primes)#list(map(lambda n: str(findDiv(n, primes)), bases))
            if divs is not None:
                results.append([coin, divs])
                print('Found', len(results), ' => ', coin, divs, file=sys.stderr)
        coin = getNextCoin(coin, length)
        if len(coin) > length:
            return results
    return results

def getLines():
    return [line.rstrip('\n') for line in sys.stdin]

lines = getLines()
nbCases = int(lines.pop(0))
print('Computing primes', file=sys.stderr)
primes = computePrimes(10**4)
print('Finish computing primes', len(primes), file=sys.stderr)

for case in range(0, nbCases):
    length, number = map(int, lines.pop(0).split(' '))
    coins = findCoins(length, number, primes)
    print("Case #", (case + 1), ":", sep="")
    for result in coins:
        print(result[0], " ", " ".join(result[1]), sep="")
