#!/usr/bin/env python
#coding: UTF-8
'''
Solve the Fair and Square excercise of Code Jam 2013

@author: Samuel Groß
'''

import math

INPUTFILE  = "/home/sam/Desktop/small.in"
OUTPUTFILE = "/home/sam/Desktop/small.out"


# ------------------- #
#      Functions      #
# ------------------- #

def is_palindrom(num):
    n = str(num)

    for i in range(len(n) / 2):
        if not n[i] == n[-(i + 1)]:
            return False

    return True


def solve(line):
    a, b  = line.split(' ')
    a = int(a)
    b = int(b)
    low   = int(math.sqrt(a) - 1)
    high  = int(math.sqrt(b) + 1)
    count = 0

    for i in range(low, high + 1):
        if is_palindrom(i):
            new = i**2
            if new >= a and new <= b and is_palindrom(new):
                print("found %i => %i" % (i, new))
                count += 1
    
    return count





if __name__ == '__main__':
    
    infile = open(INPUTFILE, 'r')
    outfile = open(OUTPUTFILE, 'w')
    
    testcases = int(infile.readline())
    counter = 1

    for line in infile:
        sol = solve(line)	
        print("[*] Case %i solved, %.2f%% done" % (counter, float(counter) * 100 / testcases))
        outfile.write("Case #%i: %s\n" % (counter, sol))
        counter += 1 
        
