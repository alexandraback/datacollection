import math
import random
import sys

def allPrimeNumbers(n):
    sifter = [1]*(n+1)
    for i in range(2, n/2+1):
        sifter[2*i] = 0
    sifter[0] = 0
    sifter[1] = 0
    for i in range(3, int(math.ceil(math.sqrt(n)))):
        if (sifter[i]):
            for j in range(i, n//i+1, 2):
                sifter[j*i] = 0
    return sifter

def transcribe(n, base):
    result = 0
    counter = 0
    while (n != 0):
        result += (n%10)*(base**counter)
        n //= 10
        counter += 1
    return result

def binary(n):
    result = 0
    while(n != 0):
        result = result*10 + n%2
        n //= 2
    return result

def isPrime(n, primes):
    if (n%2 == 0): return 2
    for i in range(2, len(primes)):
        if (primes[i] and n%i == 0): return i
    return 0

with open('test3.txt', 'r') as f:
    first_line = f.readline()
    T = int(first_line)
    second_line = f.readline()
    pieces = second_line.split(' ')
    N = int(pieces[0])
    J = int(pieces[1])

print "Case #1:"
s = []
sifter = allPrimeNumbers(10000)
#c = 2**(N-1) - 1
while (len(s) < J):
    c = random.randint(2**(N-1)+1, 2**N-1)
    n = binary(c)
##    c += 2   
##    if (sifter[n] == 0): continue
##    if (sifter[transcribe(n, 9)] == 0): continue
##    if (sifter[transcribe(n, 8)] == 0): continue
##    if (sifter[transcribe(n, 7)] == 0): continue
##    if (sifter[transcribe(n, 6)] == 0): continue
##    if (sifter[transcribe(n, 5)] == 0): continue
##    if (sifter[transcribe(n, 4)] == 0): continue
##    if (sifter[transcribe(n, 3)] == 0): continue
##    if (sifter[transcribe(n, 2)] == 0): continue

    if (c%2 == 0): continue
    if (n in s): continue
    if (isPrime(n, sifter) == 0): continue
    if (isPrime(transcribe(n, 9), sifter) == 0): continue
    if (isPrime(transcribe(n, 8), sifter) == 0): continue
    if (isPrime(transcribe(n, 7), sifter) == 0): continue
    if (isPrime(transcribe(n, 6), sifter) == 0): continue
    if (isPrime(transcribe(n, 5), sifter) == 0): continue
    if (isPrime(transcribe(n, 4), sifter) == 0): continue
    if (isPrime(transcribe(n, 3), sifter) == 0): continue
    if (isPrime(transcribe(n, 2), sifter) == 0): continue
    
##    for i in range(2, 10):
##        sys.stdout.write(str(transcribe(n, i)) + " ")
##    print n

    sys.stdout.write(str(n) + " ")
    for i in range(2, 10):
        sys.stdout.write(str(isPrime(transcribe(n, i), sifter)) + " ")
    print isPrime(n, sifter)
    s.append(n)
