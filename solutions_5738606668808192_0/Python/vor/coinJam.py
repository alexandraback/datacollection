#!/usr/bin/env python

#n is assumed to be >= 2
def getDivisor(n):
    if n == 2 or n == 3:
        return None
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3
    i = 5
    while i * i <= n:
        if n % i == 0:
            return i
        if n % (i + 2) == 0:
            return i + 2
        i += 6
    return None

def getDivisors(stringNumber):
    divisors = []
    for base in range(2, 11): #base 2 to 11 excl, i.e. base 2 to 10 incl
        n = int(stringNumber, base)
        d = getDivisor(n)
        if d == None:
            return divisors #don't care anymore
        divisors.append(d)
    return divisors

def coinJam(digits, target):
    curr = 2 ** (digits - 1) + 1 #e.g. if digits = 6, curr = 0b100001
    end = 2 ** digits - 1 #e.g. if digits = 6, curr = 0b111111
    jamsFound = 0
    while (curr <= end and jamsFound < target):
        stringNumber = bin(curr)[2:]
        divisors = getDivisors(stringNumber)
        if len(divisors) == 9:
            print stringNumber,
            for divisor in divisors:
                print divisor,
            print
            jamsFound += 1
        curr += 2

T = int(raw_input().strip())
for testCaseNo in range(T):
    digits, target = map(int, raw_input().strip().split(' '))
    print 'Case #' + str(testCaseNo + 1) + ':'
    coinJam(digits, target)
