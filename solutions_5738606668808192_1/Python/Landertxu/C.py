from itertools import product


def sieve(maxPrime):
    ans = []
    isPrime = [True] * maxPrime
    for p in range(2,maxPrime):
        if isPrime[p]:
            ans.append(p)
            for q in range(p * 2, maxPrime, p):
                isPrime[q] = False
    return ans

maxPrime = 1000
primes = sieve(maxPrime)

def getDivisor(number):
    for p in primes:
        if number % p == 0:
            return p
    return 1

def numberToBase(number, base):
    ans = 0
    for c in number:
        ans *= base
        if c == '1':
            ans += 1
    return ans

def getDivisors(number):
    listBases = range(2,11)
    ans = []
    for base in listBases:
        divisor = getDivisor(numberToBase(number, base))
        if divisor == 1:
            return []
        ans.append(divisor)
    return ans

def printNums(N, J):
    for innerCandidate in product('01', repeat=N-2):
        candidate = '1'+''.join(innerCandidate)+'1'
        divisors = getDivisors(candidate)
        if divisors:
            print candidate, ' '.join(map(str,divisors))
            J -= 1
            if J == 0:
                return

N = 32
J = 500

print "Case #1:"
printNums(N, J)