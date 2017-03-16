import math
import sys
sys.setrecursionlimit(1000000)
inf = open("in.in", "r")
ouf = open('out.out','w')

def close_files():
        inf.close()
        ouf.close()

def precount():
        pass

printcounter = 0
def printstr(a):
        global printcounter
        printcounter +=1
        print ('Case #%d: %s' % (printcounter,a), file=ouf)

full = set(range(10))
def check(s1,s2):
    #~ good = True
    for (c1,c2) in zip(s1,s2):
        if c1!=c2 and c2 !='?':
            return False
    return True
def addlead(s,n):
    s = str(s)
    while len(s)<n:
        s = '0'+s
    return s

def solvetest():
        C,J = inf.readline().split()
        l = len(C)
        diff=10**18
        c1 = 0
        c2 = 0
        for i in range(10**l):
            if check(addlead(i,l),C):
                for j in range(10**l):
                    if abs(i-j)<diff and check(addlead(j,l),J):
                        diff = abs(i-j)
                        c1 = i
                        c2 = j
        printstr(' '.join([addlead(c1,l), addlead(c2,l)]))
#precount()
testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()

