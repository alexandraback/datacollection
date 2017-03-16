import random;
import sys;

primes = [ 2, 3 ]

def ensureprimes (n):
    while (primes[-1] * primes[-1] < n):
        i = primes[-1]
        found = False

        while not found:
            i = i + 2
            
            for prime in primes:
                if prime * prime > i:
                    found = True
                if i % prime == 0:
                    break

        primes.append(i)
        
def makerandlist (n):
    num = random.getrandbits(n - 2)
    randlist = [ 1 ]

    for i in range(n - 2):
        if num & (1 << i):
            randlist.append(1)
        else:
            randlist.append(0)

    randlist.append(1)

    return randlist

def finddivisor (n):
    for prime in primes:
        if prime * prime > n:
            return 0
        elif n % prime == 0:
            return prime

    return 0

def interpret (bitlist, base):
    num = 0
    
    for i in bitlist:
        num = num * base + i

    return num

def strarr (arr):
    ret = []

    for i in arr:
        ret.append(str(i))

    return ret

def makecoins (Q, N, J):
    print "Case #" + str(Q) + ":"
    
    jamcoins = []

    while len(jamcoins) < J:
        testlist = makerandlist (N)

        divisors = []

        num = interpret (testlist, 10)
        already = False
        
        for i in jamcoins:
            if i == num:
                already = True
                break;

        if already:
            continue

        for base in range(2, 11):
            divisor = finddivisor (interpret (testlist, base))

            if divisor == 0:
                break
            else:
                divisors.append(divisor)

        if len(divisors) == 9:
            print num, ' '.join(strarr(divisors))
            
            jamcoins.append(num)

ensureprimes (1000000)

cases = int(raw_input())

for i in range(cases):
    params = raw_input().split(' ')
    
    makecoins(i + 1, int(params[0]), int(params[1]))
