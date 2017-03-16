#!/usr/bin/python

import sys

def factorial( n ):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer

def interpret_in_base( val, base ):
    answer = 0
    power = 0
    while val:
        if val%2:
            answer += base**power
        val /= 2
        power += 1
    return answer


small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

# We don't have to find them all, so if it isn't divisible by anything up to 100, we'll call it a prime
# We return a divisor or -1 to indicate prime
def weak_prime_test( val ):
    for prime in small_primes:
        if val%prime == 0 and prime < val:
            return prime
    return -1


print("Case #1:")

num_found = 0

for i in range(2**15+1,2**16,2):
#for i in range(2**5+1,2**6,2):
    interpretations = [interpret_in_base(i,base) for base in range(2,11)]
    divisors = [weak_prime_test(x) for x in interpretations]
    if -1 not in divisors:
        print "{0:b} ".format(i),
        for divisor in divisors:
            print divisor,
        print
        num_found += 1
    if num_found == 50:
        break
