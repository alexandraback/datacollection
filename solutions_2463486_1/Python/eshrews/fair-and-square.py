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
l = [0]
high = 10000000
c = 0
for i in xrange(1, high+1):
    ii = i * i
    if isPalindrome(i) and isPalindrome(ii):
        c += 1;
    
    l.append(c)


for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue
    case += 1
    ins = [int(x) for x in line.split()]
    A = ins[0]
    B = ins[1]

    sa = int(sqrt(A-1))
    sb = int(sqrt(B))
    result = l[sb] - l[sa]

    print "Case #{0}: {1}".format(case, result)

    if case == cases:
        break
