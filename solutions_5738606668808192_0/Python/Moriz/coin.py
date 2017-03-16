import math
import random
import sys

def allPrimeNumbers(n):
    sifter = [0]*(n+1)
    for i in range(1, (n+1)/2):
        sifter[2*i] = 2
    for i in range(3, int(math.ceil(math.sqrt(n)))):
        if (sifter[i] == 0):
            for j in range(i, n//i+1, 2):
                sifter[j*i] = i
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

def isPrime(n):
    if (n%2 == 0): return 2
    for i in range(3, int(math.ceil(math.sqrt(n))), 2):
        if (n%i == 0): return i
    return 0

with open('test2.txt', 'r') as f:
    first_line = f.readline()
    T = int(first_line)
    second_line = f.readline()
    pieces = second_line.split(' ')
    N = int(pieces[0])
    J = int(pieces[1])

print "Case #1:"
s = []
#sifter = allPrimeNumbers(binary(2**N-1))
#c = 2**(N-1) - 1
print binary(2**(N-1)+1)
print binary(2**N-1)
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
    if (isPrime(n) == 0): continue
    if (isPrime(transcribe(n, 9)) == 0): continue
    if (isPrime(transcribe(n, 8)) == 0): continue
    if (isPrime(transcribe(n, 7)) == 0): continue
    if (isPrime(transcribe(n, 6)) == 0): continue
    if (isPrime(transcribe(n, 5)) == 0): continue
    if (isPrime(transcribe(n, 4)) == 0): continue
    if (isPrime(transcribe(n, 3)) == 0): continue
    if (isPrime(transcribe(n, 2)) == 0): continue
    
##    for i in range(2, 10):
##        sys.stdout.write(str(transcribe(n, i)) + " ")
##    print n

    sys.stdout.write(str(n) + " ")
    for i in range(2, 10):
        sys.stdout.write(str(isPrime(transcribe(n, i))) + " ")
    print isPrime(n)
    s.append(n)
