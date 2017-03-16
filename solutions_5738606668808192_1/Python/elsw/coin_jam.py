#/usr/bin/env python
# Google Code Jam Qualification Round 2016
# C. Coin Jam
# https://code.google.com/codejam/contest/6254486/dashboard#s=p2

n, j = 32, 500
s = []
k = 0

def isPrime(number,pool=[]):
    isPrime=True
    if pool==[]:
        for i in range(2,int(number**0.5)+1):
            if number%i==0:
                isPrime=False
                break
    else:
        for i in pool:
            if number%i==0:
                isPrime=False
                break
    return isPrime

def genprimes(maximum):
    pool=[]
    n=1
    while n < maximum:
        n+=1
        if isPrime(n,pool):
            pool.append(n)
    return pool

primes = genprimes(2**15)

def factor(number,pool):
    for i in pool:
        if number%i==0:
            return number
    return 0

with open('C.out', 'w') as g:
    g.write('Case #1:\n')
    for i in xrange(2**(n-2)):
        c = bin(i)[2:]
        c = '1' + '0'*(n-2-len(c)) + c + '1'
        f = []
        for b in xrange(2, 11):
            f.append(factor(int(c,b), primes))
        f = [str(x) for x in f if x > 0]
        if len(f) == 9:
            k += 1
            g.write('%s %s\n' % (c, ' '.join(f)))
        if k == j:
            break
