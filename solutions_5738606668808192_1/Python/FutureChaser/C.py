#!/bin/python
import math

m = 32
j = 500

for n in range((1 << (m - 1)) + 1, 1 << m, 2):
    s = str(bin(n))[2:]
    factors = []
    for base in range(2, 11):
        num = int(s, base)
        flag = False
        i = 2
        while ((i * i <= num) and (i < 10000)):
            if (num % i == 0):
                flag = True
                factors.append(i)
                break
            i += 1
        if (flag == False): break
    if (len(factors) == 9):
        print(s, factors)
