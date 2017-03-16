# -*- coding: utf-8 -*-
import sys
from collections import Counter

def test(C, J):
    c = int(C)
    j = int(J)
    return abs(c-j), C, J

def solve(C, J):
    n = len(C)
    res = (10**20, '', '')
    for i in xrange(n):
        if C[i] == J[i] == '?':
            pos =[('0','9'), ('9','0'),('0','1'), ('1','0'), ('0','0')]
            for (a,b) in pos:
                c = C[:i]+a+C[i+1:]
                j = J[:i]+b+J[i+1:]
                res = min(res, solve(c, j))
            break
        elif C[i] == '?':
            pos = [J[i], '0', '1' ,'9']
            x = int(J[i])
            if x > 2:
                pos.append(str(x-1))
            if x < 8:
                pos.append(str(x+1))
            for a in pos:
                c = C[:i]+a+C[i+1:]
                res = min(res, solve(c, J))
            break
        elif J[i] == '?':
            pos = [C[i], '0', '1','9']
            x = int(C[i])
            if x > 2:
                pos.append(str(x-1))
            if x < 8:
                pos.append(str(x+1))
            for a in pos:
                j = J[:i]+a+J[i+1:]
                res = min(res, solve(C, j))
            break
    else:
        res = test(C,J)
    return res


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        C, J = f.readline().split()
        diff,c,j = solve(C,J)
        print 'Case #{t}: {c} {j}'.format(t=i+1, c=c, j=j)
        
