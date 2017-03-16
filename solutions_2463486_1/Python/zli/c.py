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

def genfas():
    fas = []
    for i in xrange(10**5+1):
        i = str(i)
        n = i+"".join(reversed(list(i)))
        if ispal(int(n)*int(n)):
            fas.append(n)
        for d in xrange(10):
            n = i+str(d)+"".join(reversed(list(i)))
            if ispal(int(n)*int(n)):
                fas.append(n)
    fas.extend([1,2,3])
    fas = set(map(int,fas))
    fas.sort()
    pickle.dump(fas,open("fas2","w"))

def incr(i):
    j=0
    while 1:
        if j == len(i):
            i.append(1)
            print len(i)
            return
        i[j] += 1
        if (j<len(i)-1 and i[j]==2) or i[j] == 3:
            i[j] = 0
            j+=1
        else:
            return

def genfas():
    fas = []
    #for i in xrange(10**5+1):
    l = [0]
    while len(l)<25:
        incr(l)
        i = "".join(map(str,l))
        n = int("".join(reversed(list(i)))+i)
        if ispal(n*n):
            fas.append(n)
        for d in xrange(3):
            n = int("".join(reversed(list(i)))+str(d)+i)
            if ispal(n*n):
                fas.append(n)
    fas.extend([1,2,3])
    fas.sort()

    pickle.dump(fas,open("fas5","w"))

fas = pickle.load(open("fas5"))

for case in range(input()):
    print "Case #"+str(case+1)+":",
    A,B=map(int,raw_input().split())
    print bisect(fas,sqrt(B)) - bisect_left(fas,sqrt(A))
