import math
import functools
import sys
#sys.setrecursionlimit(10000)
#import scipy
#f = open("A-small-attempt0.in", "r")
f = open("A-large.in", "r")
#f = open("a.txt", "r")
num_cases = int(f.readline())
cases = []
    
for c in range(num_cases):
    cases.append(f.readline())
    
def processCase(case):
    return [int(x) for x in case.split() if x!= '\n']
    
def processTest(test):
    r = test[0]
    c = test[1]
    w = test[2]
    if w == 1:
        return r*c
    count = 0
    if w == c:
        return c+(r-1)
    if r ==1:
        c2hit1 = c//w
        if c% w == 0:
            return c2hit1 + w -1
        return c2hit1 + w
    c2hit1 = c//w * r
    if c% w == 0:
        return c2hit1 + w -1
    return c2hit1 + w

 
cnum = 1
#g = open("A-out.txt", "w")
g = open("A-large-out.txt", "w")
#print(cases)
for c in cases:
    print(processCase(c))
    #print("Case #{}:".format(cnum))
    #g.write("Case #{}:\n".format(cnum))
    value = processTest(processCase(c))
    print("Case #{}: {}".format(cnum, value))
    g.write("Case #{}: {}\n".format(cnum, value))
    #print("Case #{}: {}".format(cnum, value))
    #g.write("Case #{}: {}\n".format(cnum, value))
    #print(cnum)
    cnum+=1