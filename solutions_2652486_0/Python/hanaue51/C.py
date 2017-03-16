'''
Created on 2013/04/27

@author: hanaue51
'''

import os
import math

os.chdir("../../../data/2013/round1a/")
filename = "C-small-1-attempt0"
postfix_in = ".in"
postfix_out = ".out"
results = []
format = "%s\n"

def guess(N, M, products):
    candidate = [2 for i in xrange(N)]
    
    max_primes = { 2: 0, 3: 0, 5: 0 }
    for product in products:
        p = product
        primes = { 2: 0, 3: 0, 5: 0 }
        for prime in primes:
            while p % prime == 0:
                primes[prime] += 1
                p = p / prime
        for prime in primes:
            if max_primes[prime] < primes[prime]:
                max_primes[prime] = primes[prime]
    
    if max_primes[5] >= 3:
        candidate = [5, 5, 5]
    elif max_primes[5] == 2:
        candidate[0] = candidate[1] = 5
        if max_primes[3] >= 1:
            candidate[2] = 3
        else:
            if max_primes[2] >= 2:
                candidate[2] = 4
            else:
                candidate[2] = 2
    elif max_primes[5] == 1:
        candidate[0] = 5
        if max_primes[3] >= 2:
            candidate[1] = candidate[2] = 3
        elif max_primes[3] == 1:
            candidate[1] = 3
            if max_primes[2] >= 2:
                candidate[2] = 4
            else:
                candidate[2] = 2
        else:
            if max_primes[2] >= 4:
                candidate[1] = candidate[2] = 4
            elif max_primes[2] == 3:
                candidate[1] = 2
                candidate[2] = 4
    else:
        if max_primes[3] == 3:
            candidate = [3, 3, 3]
        elif max_primes[3] == 2:
            candidate = [3, 3, 2]
            if max_primes[2] >= 2:
                candidate[2] = 4
        elif max_primes[3] == 1:
            candidate = [3, 2, 2]
            if max_primes[2] >= 4:
                candidate[1] = candidate[2] = 4
            elif max_primes[2] == 3:
                candidate[1] = 4
        else:
            if max_primes[2] >= 6:
                candidate = [4, 4, 4]
            elif max_primes[2] == 5:
                candidate = [4, 4, 2]
            elif max_primes[2] == 4:
                candidate[0] = 4
    
    return "".join([str(n) for n in candidate])

# read inputs
infile = open(os.getcwd() + "/" + filename + postfix_in, "r")
lines = infile.readlines()
infile.close()

cases_count = int(lines[0].strip())
[R, N, M, K] = [int(element) for element in lines[1].strip().split()]
for i in xrange(2, len(lines)):
    products = [p for p in [int(product) for product in lines[i].strip().split()] if p > 1]
    results.append(format % (guess(N, M, products)))

# write results
outfile = open(os.getcwd() + "/" + filename + postfix_out, "w")
outfile.write("Case #1:\n")
for result in results:
    outfile.write(result)
outfile.close()
