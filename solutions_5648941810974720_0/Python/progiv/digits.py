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
def solvetest():
        s = inf.readline().strip()
        a = [0]*255
        for c in s:
            a[ord(c)]+=1
        b = [0]*10
        b[0] = a[ord('Z')]
        b[2] = a[ord('W')]
        b[3] = a[ord('H')]-a[ord('G')]
        b[4] = a[ord('U')]
        b[5] = a[ord('F')]-a[ord('U')]
        b[6] = a[ord('X')]
        b[7] = a[ord('V')]-b[5]
        b[8] = a[ord('G')]
        b[1] = a[ord('O')]-b[0]-b[2]-b[4]
        b[9] = a[ord('I')]-b[5]-b[6]-b[8]
        ans = [str(digit)*col for (digit,col) in enumerate(b)]
        #~ print(ans)
        #~ b[3] = 
        printstr(''.join(ans))
#precount()
testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()

