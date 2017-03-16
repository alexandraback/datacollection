#!/usr/bin/python

import fileinput
from math import sqrt

def isPalindrome(n):
    s = str(n)
    for i in xrange(len(s) // 2):
        if(s[i] != s[len(s) - i - 1]):
            return False
    return True

case = 0
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue
    case += 1
    ins = [int(x) for x in line.split()]
    A = ins[0]
    B = ins[1]

    result = 0
    for a in xrange(int(sqrt(A)), int(sqrt(B))+1):
        aa = a * a
        if(aa < A):
            continue
        if(aa > B):
            break
        if(isPalindrome(a) and isPalindrome(aa)):
            result += 1

    print "Case #{0}: {1}".format(case, result)

    if case == cases:
        break
