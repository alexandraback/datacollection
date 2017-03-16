import pickle
from bisect import bisect,bisect_left
from math import sqrt

def ispal(n):
    n = str(n)
    return list(reversed(list(n)))==list(n)

def genfas():
    fas = []
    for i in xrange(10**7+1):
        if ispal(i) and ispal(i*i):
            fas.append(i)
    pickle.dump(fas,open("fas","w"))

fas = pickle.load(open("fas"))

for case in range(input()):
    print "Case #"+str(case+1)+":",
    A,B=map(int,raw_input().split())
    print bisect(fas,sqrt(B)) - bisect_left(fas,sqrt(A))
