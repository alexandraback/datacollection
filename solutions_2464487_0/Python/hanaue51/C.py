'''
Created on 2013/04/27

@author: hanaue51
'''

import os
import math

os.chdir("../../../data/2013/round1a/")
filename = "C"
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
    print max_primes
    
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
#outfile = open(os.getcwd() + "/" + filename + postfix_out, "w")
#outfile.write("Case #1:\n")
print "Case #1:"
for result in results:
    print result
#    outfile.write(result)
#outfile.close()
