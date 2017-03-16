#!/usr/bin/env python

import sys, collections
from math import sqrt, ceil, floor

def make_palindromes(s):
    #if re.search('[3-9]', str(s)): return []
    tmp = list(s)
    tmp.reverse()
    res = [int(s+"".join(tmp))]
    for i in range(3):
        if not (i == 2 and s[0] == '2'):
            res.append(int(s+str(i)+"".join(tmp)))
    return res

def check_palindrome(a):
    s = str(a)
    for i in range(len(s)/2):
        if s[i] != s[len(s)-1-i]: return False
    return True

def Solve():
    A = 1
    B = 10**14
    a = 1
    b = 10**7

    #print a, b

    lo = 1
    hi = len(str(b))/2

    
    #print lo, hi

    sample = range(1,4)
    i = lo
    base = ['1', '2']
    add = ['0', '1']

    fair = []
    while(i <= hi):
        for elm in base:
            sample.extend(make_palindromes(elm))
            for x in sample:
                if(x >= a and x <= b):
                    xx = x**2
                    if(check_palindrome(xx)): 
                        fair.append(xx)
            sample = []
        tmp = base[:]
        base = []
        for addendum in add:
            for baselem in tmp:
                if not (baselem[0] == '2' and addendum == '1'):
                    base.append(baselem+addendum)
        i += 1
    #print sample
    #print res
    #print fair
    return fair


def main():
    infile = open(sys.argv[1], 'r')
    inp = infile.readlines()
    complete = Solve()
    T = int(inp[0])
    strn = 1
    for i in range(T):
        (A, B) = map(int, inp[strn].split())
        strn += 1
        print 'Case #'+str(i+1)+": "+str(len(filter(lambda x: x >= A and x <= B, complete)))


if __name__=='__main__':
    main()
