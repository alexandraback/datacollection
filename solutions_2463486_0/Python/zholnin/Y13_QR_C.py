import sys
import itertools
import time
from files import *
#from PerfectAllocation import PerfectAllocation
from operator import itemgetter
import bisect
import math
from fractions import gcd


sys.setrecursionlimit(1000) #1000 is defaul

def numtostring(a, n):
    s = ""
    b = n
    i = 0
    while a <> 0:
        s = str((a%b)) + s
        i += a%b
        a = a / b
        
    return s, i

def next_permutation(L):
    B = len(L) - 1
    while L[B] <= L[B-1]:
        B = B - 1
        if (B == 0):
            return None
    
    b = B
    for x in range(B, len(L)):
        if L[b] > L[x] and L[x] > L[B-1]:
            b = x
    
    (L[b], L[B - 1]) = (L[B - 1], L[b])
    L = L[:B] + sorted(L[B:])
    return L

Answers = []

def Test(num):
    num = str(int(num) ** 2)
    for x in range(0, len(num) /2 + 1):
        if num[x] <> num[len(num) - x - 1]:
            return False
    return True
    


def preprocess():
    def process_all(y):
        assert (len(y) == 26)
        sumy = sum([int(o) for o in y])
        insertion = ["1"]
        if sumy > 0:
            insertion += ["", "0"]
        
        if sumy < 4:
            insertion += ["2", "3"]

        if sumy < 3:
            insertion += ["4", "5"]

        if sumy < 2:
            insertion += ["6", "7"]

        
        while True:
            num = "".join(y).lstrip("0")
            for i in insertion:
                num1 = num + i + num[::-1] 
                

                if Test(num1):
                    Answers.append(int(num1))
            
            y = next_permutation(y)
            if y == None:
                break
        
    
    # only zeros and ones
    x = ['0'] * 22 + ['1'] * 4
    process_all(x)
    x = ['0'] * 23 + ['1'] * 3
    process_all(x)
    x = ['0'] * 24 + ['1'] * 2
    process_all(x)
    x = ['0'] * 25 + ['1'] * 1
    process_all(x)
    x = ['0'] * 23 + ['1'] * 2 + ['2'] * 1
    process_all(x)
    x = ['0'] * 24 + ['1'] * 1 + ['2'] * 1
    process_all(x)
    x = ['0'] * 25 + ['2'] * 1
    process_all(x)
    x = ['0'] * 24 + ['2'] * 2
    process_all(x)
    x = ['0'] * 25 + ['3'] * 1
    process_all(x)
    x = ['0'] * 24 + ['1'] * 1 + ['3'] * 1
    process_all(x)
    x = ['0'] * 26
    process_all(x)
    
    
    #zeros, ones and twos
    
    print len(Answers)
    Answers.sort()
           
    return

def solve_case():
    (A, B) = Input.readints()
    
    a = 0
    b = 0
    
    while Answers[a]**2 < A:
        a += 1
        
    b = a
    
    while Answers[b]**2 <= B:
        b += 1
    
    return b - a







start_time = time.time()

Input = File("input.txt", "r")
Output = File("output.txt", "w")

n_cases = Input.readint()
preprocess()

for n in range(n_cases):
    solution = solve_case()
    Output.write("Case #" + str(n+1) + ": " + str(solution) + "\n")
    print "Case #" + str(n+1) + ": " + str(solution)

    TOT = (time.time() - start_time) / (n + 1) * n_cases
    if TOT > 120:
        print "Running over two minutes by:", int (TOT - 120), "seconds"
    
print time.time() - start_time, "seconds"
