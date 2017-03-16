#!/usr/bin/python -OO

import sys;
import os.path; 
from collections import *;
from Queue import *;
import numpy as np;

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def reads():
    return sys.stdin.readline().strip();

primes = [2];

def getDivisor(num):
    for p in primes:
        if num % p == 0:
            return p;
        if p * p > num:
            break;
    return 0;

def genPrimes(maxNum):
    for num in xrange(3, maxNum, 2):
        if getDivisor(num) == 0:
            primes.append(num);

def genArray(numBits):
    middleBits = np.random.choice(2, numBits - 2);
    bits = np.concatenate(([1], middleBits, [1]));
    return bits;

def getNumInRadix(arr, radix):
    num = 0;
    for n in arr:
        num = num * radix + n;
    return num

radixes = range(2, 11);

def genNonPrime(numBits):
    divisors = [0] * 9;
    while True:
        arr = genArray(numBits);
        print >> sys.stderr, "trying ", arr
        allNonPrime = True;
        for radix in radixes:
            num = getNumInRadix(arr, radix);
            divisor = getDivisor(num);
            if divisor == 0:
                print  >>sys.stderr, "in radix", radix, "it's prime: ", num;
                allNonPrime = False;
                break;
            print  >>sys.stderr, "in radix", radix, "it's", num, "and has divisor", divisor;
            divisors[radix - 2] = divisor;

        if allNonPrime:
            return (getNumInRadix(arr, 2), "".join(str(x) for x in arr),  divisors);

def main():
    genPrimes(100000)
    nt = readi();
    for t in range(1, nt+1):
        (numBits, numToGen) = readia();
        generatedNums = set();
        genResults = [];

        print >>sys.stderr, "Generating bits ", numBits, ", to gen ", numToGen
        while len(genResults) < numToGen:
            genRes = genNonPrime(numBits);
            if genRes[0] not in generatedNums:
                genResults.append(genRes);

        print "Case #%d:" % t;
        for genRes in genResults:
            print "%s %s" % (genRes[1], " ".join(str(x) for x in genRes[2]));
    

main();
