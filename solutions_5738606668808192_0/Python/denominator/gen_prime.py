#!/usr/bin/env python2.7 -u

import math

def isPrime(n):  
    if n <= 1:  
        return False, -1
    for i in range(2, int(math.sqrt(n)) + 1):  
        if n % i == 0:  
            return False, i 
    return True, -1


print 'Case #1:'
res_c = 0
for n in range(int('1'+'0'*14+'1',2),int('1'*16, 2) + 1):
    n_str = bin(n)[2:]
    if n_str[-1] != '1':
        continue

    res = False
    dd = []
    for r in range(2, 11):
        n_r = int(n_str, r)
        isp, d = isPrime(n_r)
        res = res or isp
        dd.append(d)

    if not res:
        print n_str + ' ' + ' '.join(map(str,dd))
        res_c += 1
    if res_c == 50:
        break

