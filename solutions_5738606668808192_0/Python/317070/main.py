import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import numpy as np
import itertools
import math
import itertools
import random
from collections import defaultdict




def solve(N,J):
    # J numbers of N digits
    print N,J
    prime_list = []
    for i in gen_primes():
        prime_list.append(i)
        if i>10**(N/2):
            break

    jamcoins = []

    for number in xrange((2**(N-1))+1, 2**N, 2):
        print number

        isjamcoin = True
        for base in xrange(2,11):
            n_in_base = convert_to_base(number,b=base)
            #print "n_in_base",n_in_base
            if is_prime(n_in_base, prime_list):
                isjamcoin = False
                break

        if isjamcoin:
            print "JAM"
            jamcoins.append(number)
            if len(jamcoins)==J:
                #pass
                break
    results = []
    for j in jamcoins:
        results.append([convert_to_base(j,b=10)])
        for base in xrange(2,11):
            n_in_base = convert_to_base(j,b=base)
            d = get_divisor(n_in_base, prime_list)
            results[-1].append(d)
    return results

    return ""


def get_divisor(number, prime_list):

    for p in prime_list:
        if p>math.sqrt(number):
            return None
        if number%p==0:
            #print number, p
            return p
    return None

def is_prime(number, prime_list):

    for p in prime_list:
        if p>math.sqrt(number):
            return True
        if number%p==0:
            #print number, p
            return False
    return True

def convert_to_base(number, b):
    # number is in base 2,
    # what would it be in base b
    res = 0
    dig = 1
    while number != 0:
        if number%2==1:
            res += dig
        number = number/2
        dig = dig*b
    return res

def gen_primes():
    D = {}
    q = 2
    while True:
        if q not in D:
            yield q
            D[q * q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1


output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):

        ### calculate answer ###
        N,J = read_ints()
        answer = solve(N,J)

        ### output ###

        answer_str = "Case #1:\n"
        for a in answer:
            answer_str += str(a).replace(',','').replace('[','').replace(']','')+'\n'
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()