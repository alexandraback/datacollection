from __future__ import print_function
import sys, random

# print to stderr for debugging
enableDebug = True
def printe(*stuff):
    if enableDebug:
        print(*stuff, file=sys.stderr) 


# Open file for processing
filename = sys.argv[1]
inputFile = open(filename, 'r')
lines = [l.rstrip('\n') for l in inputFile]
linesIter = iter(lines)
nCases = int(linesIter.next())



# Generate small primes for checking bigger numbers approximately
nSmall = 200000
isPrime = [True]*nSmall
smallPrimes = []
for i in range(2,nSmall):
    if isPrime[i]:
        smallPrimes.append(i)
        val = i
        while val < nSmall:
            isPrime[val] = False
            val += i

# printe("Found small primes " + str(smallPrimes))



# Interpret a coin as a number encoded in the given base
def coinInBase(coin, base):
    basePow = 1
    val = 0
    for i in range(len(coin)-1, -1, -1):
        if coin[i]:
            val += basePow
        basePow *= base

    return val


def isComposite(x):

    for sp in smallPrimes:
        if x == sp or sp > x:
            return None
        if x % sp == 0:
            return sp
    return None


# Process each case
for iCase in range(1,nCases+1):
    printe("\nProcessing case " + str(iCase))

    # Solve problem
    vals = next(linesIter).split(" ")
    N = int(vals[0])
    J = int(vals[1])


    jamCoins = []
    seenCoins = set()
    while(len(jamCoins) < J):

        # Generate a potential jamcoin
        middle = [random.randint(0,1) == 0 for _ in range(N-2)]
        coin = tuple([True] + middle + [True])

        # Make sure we haven't seen this one before
        if coin in seenCoins:
            continue
        seenCoins.add(coin)


        # Check if this coin is composite in every base, retaining the divisor if it is
        # Spoiler: there's a pretty good chance it is
        allComp = True
        factorsList = []
        for base in range(2,11):
    
            coinVal = coinInBase(coin, base)
            factor = isComposite(coinVal)

            if factor is None:
                allComp = False
                break
            
            factorsList.append(factor)


        if allComp:
            jamCoins.append((coin, factorsList))


    print("Case #{}:".format(iCase))
    for coin,factors in jamCoins:
        coinStr = "".join(['1' if val else '0' for val in coin])
        factorStr = " ".join([str(f) for f in factors])
        print(coinStr + " " + factorStr)


























