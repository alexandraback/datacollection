#!/usr/bin/env python2.7 -u

import math
import sys

def isPrime(n): 
    if n <= 1:
        return False, -1
    for i in xrange(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False, i
    return True, -1

def isSuedoPrime(n): 
    th = 10000
    if n <= 1:
        return False, -1
    for i in xrange(2, th):
        if n % i == 0:
            return False, i
    return True, -1

print 'Case #1:'
res_c = 0
st = int('1'+'0'*30+'1',2)
ed = int('1'*32, 2)
for n in xrange(st, ed + 1):
    sys.stderr.write(str(n) + '\n')
    if n % 100 == 0:
        sys.stderr.write(str(n) + '\n')
    n_str = bin(n)[2:]
    if n_str[-1] != '1':
        continue
    res = False
    dd = []
    for r in xrange(2, 11):
        n_r = int(n_str, r)
        #isp, d = isPrime(n_r)
        isp, d = isSuedoPrime(n_r)
        res = res or isp
        if res:
            break
        dd.append(d)
    if not res:
        print n_str + ' ' + ' '.join(map(str,dd))
        res_c += 1
    if res_c == 500:
        break

