from math import sqrt
import primes

def isPrime(n, base):
    val = 0
    exponent = 1
    for i in n[::-1]:
        val += i*exponent
        exponent *= base
    maxPrime = int(sqrt(val))

    for p in primes.primeList:
        if p > maxPrime:
            break
        if val%p == 0:
            return False,p
    return True,0

def run():
    caseCount = int(input())
    for caseIndex in range(caseCount):
        print("Case #%d:" % (caseIndex+1))
        result = 0
        inVals = input().split(' ')
        coinLength = int(inVals[0])
        coinCount = int(inVals[1])

        coinsFound = 0
        divisors = [0]*9

        coin = [0]*coinLength
        coin[0] = 1
        coin[-1]= 1
        for coinIndex in range(2**(coinLength-2)):
            coin[-2] += 1
            for i in range(coinLength-2,0,-1):
                if coin[i] == 2:
                    coin[i-1] += 1
                    coin[i] = 0

            isValid = True
            for base in range(2,11):
                prime,divisor = isPrime(coin, base)
                if not prime:
                    divisors[base-2] = divisor
                else:
                    isValid = False
                    break
            if isValid:
                coinsFound += 1
                coinStr = "".join([str(x) for x in coin])
                divisorStr = " ".join([str(x) for x in divisors])
                print("%s %s" % (coinStr, divisorStr))

            if coinsFound >= coinCount:
                break

run()
