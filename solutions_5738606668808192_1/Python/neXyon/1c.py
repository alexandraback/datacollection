#!/usr/bin/python3
# coding: utf-8

import sys
import numpy as np

primes = np.arange(2, 1000000)

i = 0

while i < len(primes):
    primes = primes[np.logical_or(primes % primes[i] != 0, primes <= primes[i])]
    i += 1

def compute(length, count, output_file):
    global primes
    
    jamcoins = []
    while len(jamcoins) < count:
        bits = np.ones(length, np.uint64)
        bits[1:-1] = np.random.randint(2, size=length - 2)

        base = 10
        coin = np.sum(bits[::-1] * (base ** np.arange(length, dtype='object')))

        if coin in jamcoins:
            continue

        divisors = np.zeros(9, np.int32)

        for base in range(2, 11):
            value = np.sum(bits[::-1] * (base ** np.arange(length, dtype='object')))

            for divisor in primes:
                if divisor >= value:
                    break

                if value % divisor == 0:
                    divisors[base - 2] = divisor
                    break

            if divisors[base - 2] == 0:
                break

        if np.all(divisors):
            jamcoins.append(coin)
            output_file.write(str(coin))
            for divisor in divisors:
                output_file.write(' ' + str(divisor))
            output_file.write('\n')

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline()
    
    length, coin_count = [int(x) for x in input_line.split(' ')]
    
    result = 'Case #{0}:\n'.format(i + 1)
    
    output_file.write(result)
    
    result = compute(length, coin_count, output_file)

