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

numbers = []        # global cache for all valid numbers

def generate():
    global numbers
    if not numbers:
        # need to fill
        for i in range(int(math.sqrt(10**14) + 2)):
            if is_palindrom(i):
                new = i**2
                if is_palindrom(new):
                    print("found %i => %i" % (i, new))
                    numbers.append(new)

    return numbers
 

def is_palindrom(num):
    n = str(num)

    for i in range(len(n) / 2):
        if not n[i] == n[-(i + 1)]:
            return False

    return True


def solve(line):
    a, b = map(int, line.split(' ')) 
    count = 0
    
    for i in generate():
        if a <= i <= b:
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
        
