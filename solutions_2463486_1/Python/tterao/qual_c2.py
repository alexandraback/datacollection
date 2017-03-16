'''
Created on 2012/04/14

@author: teraotsuyoshi
'''

from itertools import *

def xperm(item, n):
    for x in combinations_with_replacement(item, n):
        for y in permutations(x):
            yield y

def nextPali(n):

    for i in range(1,10):
        yield i
    
    for i in range(1,10):
        s = "%d%d"%(i,i)
        yield int(s)
    
    for j in range(2,n):
        for i in xperm("012", j):
            if i[0] == "0":
                continue
            s = list(i)
            t = list(i[:-1])
            t.reverse()
            s = s + t
            yield int("".join(s))
        
        for i in xperm("012", j):
            if i[0] == "0":
                continue
            s = list(i)
            t = list(i)
            t.reverse()
            s = s + t
            yield int("".join(s))
    

def isPali(x):
    s = "%d"%(x)
    for i in range(len(s)/2):
        if s[i] != s[-(i+1)]:
            return False
    
    return True
        
if __name__ == '__main__':

    t = set()
    
    for x in nextPali(8):
        y = x**2
        if isPali(y):
            t.add(y)
    
    lines = open("C-large-1.in").readlines()
    T = int(lines[0])
    for i in range(1, T+1):
        (A,B) = lines[i].split()[:2]
        A = int(A)
        B = int(B)

        count = 0
        for x in t:
            if A <= x and x <= B:
                count = count + 1

        print "Case #%d:"%i, count
                
        
