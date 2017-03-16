import math
import sys
sys.setrecursionlimit(1000000)
inf = open("in.in", "r")
ouf = open('out.out','w')

def close_files():
        inf.close()
        ouf.close()

printcounter = 0
def printstr(a):
        global printcounter
        printcounter +=1
        print ('Case #%d: %s' % (printcounter,a), file=ouf)
def rotate(a, r=1):
    n = len(a)
    t= list(a)
    return t[r%n:]+t[:r%n]

def solvetest():
        j,p,s,k = map(int, inf.readline().split())
        jp = [[0]*p for i in range(j)]
        js = [[0]*s for i in range(j)]
        ps = [[0]*s for i in range(p)]
        ans = [0]
        for ss in range(s):
            for pp in rotate(range(p), ss*k):
                for jj in rotate(range(j), pp*k):
                    if jp[jj][pp]<k and js[jj][ss]<k and ps[pp][ss]<k:
                        ans.append(' '.join(map(str, [jj+1, pp+1, ss+1])))
                        jp[jj][pp]+=1
                        js[jj][ss]+=1
                        ps[pp][ss]+=1
        ans[0] = str(len(ans)-1)
        printstr('\n'.join(ans))

testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()

