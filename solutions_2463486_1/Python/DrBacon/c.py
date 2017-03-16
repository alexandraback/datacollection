#!/usr/bin/python

import os
import sys
import math

fn = sys.argv[1]

fh = open(fn, "r")
T = int(fh.readline().strip())
cases = []

for i in range(T):
    case = {}
    [A, B] = map(int, fh.readline().strip().split())
    case["A"] = A
    case["B"] = B
    cases.append(case)

fh.close()

def is_palindrome(x):
    return "".join([k for k in str(x)][::-1]) == str(x)

def make_palindromes(x):
    str_x = str(x)
    reversed = "".join([k for k in str_x][::-1]) 
    return [int(str_x+reversed), int(str_x[:-1]+reversed)]

"""
adapted from http://stackoverflow.com/questions/5110177/how-to-convert-floating-point-number-to-base-3-in-python
"""
def base3int(x):
    x = int(x)
    exponents = range(int(math.log(x, 3)), -1, -1)
    r = ""
    for e in exponents:
        d = int(x // (3 ** e))
        x -= d * (3 ** e)
        r+=str(d)
    return r

def numbers_012(digits = 4):
    return map(lambda x: int("".join(base3int(x))), range(1,pow(3,digits)))
        
    
def make_all_palindromes(max_pow = 3):
    palindromes = []
    for i in numbers_012(digits=max_pow/2):
        palindromes += make_palindromes(i)
    fs_palindromes = [9]
    for p in palindromes:
        if is_palindrome(p*p):
            fs_palindromes+=[ p*p ]
    return sorted(fs_palindromes)

def determine_case(case):
    A = case["A"]
    B = case["B"]
    return str(len(filter(lambda x: A <= x <= B, known_fp_palindromes)))


known_fp_palindromes = make_all_palindromes(15)


fh_o = open("out.txt","w")
for i, case in enumerate(cases):
    print >> fh_o, "Case #"+str(i+1)+": "+ determine_case(case)


fh_o.close()

