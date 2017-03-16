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
        C = list(C)
        J = list(J)
        l = len(C)
        sign = 0
        for i in range(l):
            if sign == 0:
                if C[i] == '?' and J[i] !='?':
                    C[i] = J[i]
                elif C[i]!='?' and J[i] == '?':
                    J[i] = C[i]
                elif C[i]!= '?' and J[i] !='?':
                    if C[i]>J[i]:
                        sign = 1
                    elif C[i]<J[i]:
                        sign = -1
                else:
                    if i == l-1:
                        C[i] = J[i] = '0'
                    elif C[i+1]=='?' or J[i+1]=='?':
                        C[i] = J[i] = '0'
                    else:
                        if ord(C[i+1])-ord(J[i+1])>5:
                            C[i] = '0'
                            J[i] = '1'
                            sign = -1
                        elif ord(J[i+1])-ord(C[i+1])>5:
                            C[i] = '1'
                            J[i] = '0'
                            sign = 1
                        else:
                            C[i] = '0'
                            J[i] = '0'
            elif sign == 1:
                if C[i] == '?':
                    C[i] = '0'
                if J[i] == '?':
                    J[i] = '9'
            else:
                if C[i] == '?':
                    C[i] = '9'
                if J[i] == '?':
                    J[i] = '0'
        C = ''.join(C)
        J = ''.join(J)
        printstr(' '.join([C,J]))
#precount()
testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()

