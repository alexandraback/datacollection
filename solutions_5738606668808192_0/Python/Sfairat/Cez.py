
# coding: utf-8

# In[26]:

import random
import sys

def genRandomNum(symbCount) :
    retVal = [1]
    for i in range(0, symbCount - 2) :
        nextSymb = random.randint(0, 1)
        retVal.append(nextSymb)
    retVal.append(1)
    return retVal

def arrayToNumber(digits, base) :
    res = 0
    for i in range(0, len(digits)) :
        res = res * base
        res = res + digits[i]
    return res

def genPrimes(upTo) :
    primes = [2]
    curNum = 3
    while curNum < upTo :
        good = 1
        for i in range(0, len(primes)) :
            if curNum % primes[i] == 0 :
                good = 0
                break
            if i * i > curNum :
                break
        if good :
            primes.append(curNum)
        curNum += 2
    return primes

def printArr(arr) :
    for i in range(0, len(arr)) :
        sys.stdout.write("%d" % (arr[i]))
#     sys.stdout.write("\n")

sys.stdout.write("Case # 1: \n")
count = 0
charCount = 16
primes = genPrimes(500)
# print(primes)
its = 0
targetCount = 50
while count < targetCount:
    digits = genRandomNum(charCount)
    divisors = []
    for base in range(2, 11) :
        found = 0
        num = arrayToNumber(digits, base)
        for pn in primes :
            if num % pn == 0 :
                found = 1
                divisors.append(pn)
                break
        if found == 0 :
            break
    if len(divisors) == 9:
#         print ("found")
        printArr(digits)
        sys.stdout.write(" ")
        for i in range(0, len(divisors)) :
            sys.stdout.write("%d " % (divisors[i]))
        sys.stdout.write("\n")
        count = count+1
#     else :
#         print ("bad")
        
#     its = its + 1
#     if its == 700 :
#         break

