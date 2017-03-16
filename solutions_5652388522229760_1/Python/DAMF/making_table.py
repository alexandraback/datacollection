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

print("0")
for N in range(1,(10**6)+1):
    numbers_seen = set()
    for i in range(1,1000):
        multiple = i*N
        digits = str(multiple)
        for digit in digits:
            numbers_seen.add(digit)
        if len(numbers_seen) == 10:
            print(multiple)
            break
    if i == 1000:
        print("INSOMNIA")

