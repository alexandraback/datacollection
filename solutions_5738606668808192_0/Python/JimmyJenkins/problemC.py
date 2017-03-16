# -*- coding: utf-8 -*-
"""
Created on Mon Mar 28 18:50:14 2016

@author: James
"""

import sys
import os
import math
from collections import deque

def to_binary(num):
    digits = deque([])
    while num > 0:
        digits.appendleft(str(num & 1))
        num = num >> 1
    return ''.join(digits)

def sieve(max_prime):
    max_root = int(math.sqrt(max_prime)) + 1
    primes = [1] * (max_prime + 1)
    primes[0], primes[1] = 0, 0
    for i in range(4, max_prime + 1, 2):
        primes[i] = 0
    for i in range(3, max_root + 1, 2):
        if primes[i] == 0:
            continue
        for j in range(i * i, max_prime + 1, i):
            primes[j] = 0
    return [i for i, p in enumerate(primes) if p == 1]
        

def is_coin_jam(coin, primes):
    divisors = []
    for i in range(2, 11):
        cointerpretation = int(coin, i)
        for p in primes:
            if p**2 > cointerpretation:
                return (False, None)
            if cointerpretation % p == 0:
                divisors.append(p)
                break
    else:
        return (True, divisors)
                
    
    
def rdln(txtin):
    return txtin.readline().strip()

def file_io():
    file_names = 'problemC'
    with open(''.join([file_names, '.in'])) as txtin:
        with open(''.join([file_names, '.out']), 'w') as txtout:
            case_count = int(rdln(txtin))
            for i in range(case_count):
                txtout.write(''.join(['Case #', str(i + 1), ':\n']))
                N, J = (int(x) for x in rdln(txtin).split())
                max_interpretation = int('1' * N)
                max_prime = int(math.sqrt(max_interpretation)) + 1
                inner_str_max = int('1'*(N-2), 2)
                primes = sieve(max_prime)
                coins_found = 0
                for j in range(inner_str_max + 1):
                    coin_candidate = to_binary(j).zfill(N - 2).join(['1']*2)
                    is_coin, divisors = is_coin_jam(coin_candidate, primes)
                    if is_coin:
                        coins_found += 1
                        txtout.write(coin_candidate + ' ')
                        for divisor in divisors:
                            txtout.write(str(divisor) + ' ')
                        txtout.write('\n')
                    if coins_found >= J:
                        break

    osCommandString = ''.join(['notepad.exe ', file_names, '.out'])
    os.system(osCommandString)

def main():
    """Main"""
    file_io()
    #primes = sieve(111111)
    #print(is_coin_jam('100011', primes))

if __name__ == '__main__':
    sys.exit(main())
