import math
import functools
import sys

import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
#sys.setrecursionlimit(10000)
#import scipy
f = open("B-small-attempt1.in", "r")
#f = open("B-large.in", "r")
#f = open("b.txt", "r")
num_cases = int(f.readline())
cases = []
    
for c in range(num_cases):
    cases.append([f.readline(),f.readline(),f.readline()])
    
def processCase(case):
    t1 =  [int(x) for x in case[0].split() if x!= '\n']
    return [t1, case[1], case[2]]
    
def processTest(test):
    k = test[0][0]
    l = test[0][1]
    s = test[0][2]
    keys = test[1].strip('\n')
    target = test[2].strip('\n')
    #print keys, target, s
    for x in target:
        if x not in keys:
            return 0.0
    overlap = max(count_overlaps(target)-1, 0)
    #print overlap, 'ol'
    fit = s-l+1
    worst = min(s/(l-overlap), fit)
    #print worst, 'worst'
    chance = 1
    for x in target:
        occur = keys.count(x)
        prob = occur*1.0/len(keys)
        chance *= prob
    expected = 0
    #print chance
    for x in range(worst+1):
        expected += nCr(worst, x)*x*(chance)**x * (1-chance)**(worst-x)
        #print expected, 'ee'
    #print expected
    return worst - expected
def count_overlaps(string):
    rev = string[::-1]
    count = 0
    endex = -1
    startex = 1
    for i in range(len(string)):
        #print i
        if string[endex:] == string[:startex]:
            #if string == "IGI":
                #print string[endex:], string[:startex]
            count +=1
            #print count
        endex -= 1
        startex +=1

    return count
cnum = 1
g = open("B-out.txt", "w")
#g = open("B-large-out.txt", "w")
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