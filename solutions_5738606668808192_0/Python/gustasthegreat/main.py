#!/bin/python
import random

def primegen(count):
    primes = [2]
    for a in range(3, count):
        notPrime=0
        for b in primes:
            if b*b > a:
                break
            if a%b == 0:
                notPrime=1
                break;
        if notPrime == 0:
            primes.append(a)
    return primes

def isPrime(n, primes):
    for p in primes:
        if p * p > n:
            return 0
        if n%p == 0:
            return p
    return 0

def basen(a, n):
    a = int(str(a), n)
    ret = []
    while a > 0:
        ret.append(str(a%n))
        a //= n
    return int(''.join(ret))

def main():
    p = primegen(10000)
    input()
    n, k = input().split()
    n, k = int(n), int(k)
    ans = []
    tested = set()
    while len(ans) < k:
        number = int('1'+''.join([random.choice(['1', '0']) for i in range(n-2)]) + '1')
        if number in tested:
            continue
        tested.add(number)
        good = 1
        factors = []
        for base in range(2, 11):
            factors.append(str(isPrime(int(str(number),base), p)))
            if factors[-1] == '0':
                good = 0
                break
        if good:
            ans.append((number, factors))
    print("Case #1:")
    for a,b in ans: 
        print("{} {}".format(a, ' '.join(b)))


if __name__=="__main__":
    main()
