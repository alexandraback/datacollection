#!/usr/bin/python

import sys
infile = sys.stdin
#infile = open('in.txt', 'r')

def palindromes(ndigits):
    for d in range(ndigits+1):
        odd = bool(d % 2)

        low = int(10**((d-1)/2))
        high = int(10**((d+1)/2))

        for n in range(low, high):
            r = n
            v = n
            if odd:
                v /= 10
        
            while v != 0:
                r *= 10
                r += v % 10
                v /= 10
        
            yield r

def ispal(n):
    s = str(n)
    l = len(s)
    for i in range((l+1) / 2):
        if s[i] != s[-(i+1)]:
            return False
    return True
    

T = int(infile.readline())
for t in range(T):
    A, B = map(int, infile.readline().split())
    
    cnt = 0
    for n in palindromes((len(str(B)) + 1) / 2):
        sq = n*n
        if sq < A: continue
        if sq > B: break
        
        if ispal(sq):
            #print sq
            cnt += 1
    
    print 'Case #%d: %d' % (t+1, cnt)
