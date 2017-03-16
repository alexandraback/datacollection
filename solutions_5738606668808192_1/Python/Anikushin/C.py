import sys
from copy import *
from math import *
    
n, m = 32, 500
limit = 100000
a = [0] * n
a[0] = a[n-1] = 1

divs = []
mmax = 1000000
tmp = range(mmax)
for i in range(2, mmax):
    if tmp[i] != -1:
        divs.append(i)
    k = 1
    while k*i < mmax:
        tmp[k*i] = -1
        k += 1

print divs[:20]

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
    for d in divs:
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
    print len(res), a
    next(a)

with open("out.txt", "w") as f:
    f.write("Case #1:\n")
    for a in res:
        f.write("".join(map(str, a)))
        for k in range(2,11):
            s = 0
            for c in a:
                s = s * k + c
            for d in divs:
                if s % d == 0:
                    f.write(" %d" % d)
                    break
        f.write("\n")
