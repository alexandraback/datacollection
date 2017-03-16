# -*- coding: utf-8 -*-
"""

@author: Robo
"""

import os
import numpy as np

folder = "D:/CODE/googlecodejam/jamcoin"
infile = "C-small-attempt0.in"
outfile = "C-small-attempt0.out"


def read_gcj_input():
    cases = []
    with open(os.path.join(folder,infile), 'r') as f:
        for each in xrange(int(f.readline())):
            Araw = f.readline().strip()
            N,J = [int(i) for i in Araw.split(' ')]
            cases.append({'N': N, 'J': J})
    return cases

# from https://www.daniweb.com/programming/software-development/code/216880/check-if-a-number-is-a-prime-number-python
# but modified to give divisors
def isprime(n):
    '''check if integer n is a prime'''
    # make sure n is a positive integer
    n = abs(int(n))
    # 0 and 1 are not primes
    if n < 2:
        return None
    # 2 is the only even prime number
    if n == 2: 
        return None  
    # all other even numbers are not primes
    if not n & 1: 
        return 2
    # range starts with 3 and only needs to go up the squareroot of n
    # for all odd numbers
    for x in range(3, int(n**(0.5))+1, 2):
        if n % x == 0:
            return x
    return None
    
cases = read_gcj_input()


with open(os.path.join(folder,outfile), 'w') as f:
    for index,case in enumerate(cases):
        N = case['N']
        J = case['J']
        f.write('Case #{0}:\n'.format(index+1))
        
        jcount = 0
        num=0
        #use binary to create the inbetween values, iterate, brute force!
        while jcount < J and num<2**(N-2):
            numbase2 = np.binary_repr(num,width=N-2)
            jamStr='1'+numbase2+'1'
            
            jamValues = [int(jamStr,base+2) for base in xrange(9)]
#            print jamValues
            notPrime = True
            divs = ''
            for val in jamValues:
                div = isprime(val)
                if div:
                    divs = divs + ' ' + str(div)
                else:
                    notPrime = False
                    break
#            print divs
            if notPrime:
                f.write('{0} {1}\n'.format(jamStr, divs))
                jcount+=1
            num+=1
