import math

def isPrime(n):
    return all(n%i!=0 for i in range(2, int(math.sqrt(n))+1))

def findPrimes(m):
    #returns a set of prime integers less than m
    primes = set()
    for i in range(2, m+1):
        if isPrime(i):
            primes.add(i)
    return primes

primes = sorted(list(findPrimes(int(math.sqrt(2**32))+1)))

def findDivisor(n):
    #returns the smallest divisor for n, or False if n is prime
    sqrtn = int(math.sqrt(n))+1
    for p in primes:
        if n%p == 0:
            return p
        if p > sqrtn:
            return False
    return False

def binary2basen(s, n):
    #returns the decimal representation of the binary string s
    #interpreted in base n
    return 0 if len(s)==0 else n*(binary2basen(s[:-1], n)) + (1 if s[-1]=='1' else 0)

def checkCoin(s):
    #checks if a given jamcoin s, given as a string, is valid
    #if valid, returns a list of divisors
    #if invalid, return False
    divisors = []
    for base in range(2, 11):
        divisor = findDivisor(binary2basen(s, base))
        divisors.append(divisor)
        if not divisor:
            return False
    return divisors

T = input()
N, J = map(int, raw_input().split(" "))
print "Case #1:"

i = 0
count = 0
while count < J:
    binary = bin(i)[2:] 
    coin = "1" + "0"*(N-2-len(binary)) + binary + "1"
    divisors = checkCoin(coin)
    if divisors:
        print coin + " " + " ".join(map(str, divisors))
        count += 1
    i += 1

