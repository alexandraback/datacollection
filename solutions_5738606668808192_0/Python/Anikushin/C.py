import sys
from copy import *
from math import *
    
n, m = 16, 50

a = [0] * n
a[0] = a[n-1] = 1

def next(a):
    for i in range(1, len(a)-1):
        if a[i] == 0:
            a[i] = 1
            return
        else:
            a[i] = 0
            
def check(a, k):
    s = 0
    for c in a:
        s = s * k + c
    print a, k, s        
    for d in xrange(2, int(sqrt(s))):
        if s % d == 0:
            return True
    return False
    
res = []
while len(res) < m:
    good = False
    while not good:
        good = True
        for k in range(2,11):
            good = good and check(a,k)
        if good:
            break
        next(a)
    res.append(copy(a))
    next(a)

with open("out.txt", "w") as f:
    f.write("Case #1:\n")
    for a in res:
        f.write("".join(map(str, a)))
        for k in range(2,11):
            s = 0
            for c in a:
                s = s * k + c
            for d in xrange(2, int(sqrt(s))):
                if s % d == 0:
                    f.write(" %d" % d)
                    break
        f.write("\n")
