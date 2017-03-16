#!/usr/bin/env python

import sys
from bitarray import bitarray

t = int(sys.stdin.readline())

def is_palindrome(x):
    return str(x) == ''.join(reversed(str(x)))

fairsquares = list()
for num in xrange(9999,0,-1):
    pal = int(str(num) + ''.join(reversed(str(num))))
    cand = pal * pal
    if is_palindrome(cand):
        fairsquares.append(cand)
    pal = int(str(num) + ''.join(reversed(str(num)[:-1])))
    cand = pal * pal
    if is_palindrome(cand):
        fairsquares.append(cand)

for testcase in xrange(t):
    [a,b] = map(int,sys.stdin.readline().split())
    print 'Case #' + str(testcase+1) + ': ' + str(sum(a<=fs<=b for fs in fairsquares))



