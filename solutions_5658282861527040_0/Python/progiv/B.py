import math, sys
if len(sys.argv) > 1:
    inFile = sys.argv[1]
else:
    inFile = "in.txt"
inf = open(inFile, "r")
ouf = open("out.txt","w")

def close_files():
    inf.close()
    ouf.close()

printcounter = 0
def printstr(a):
    global printcounter
    printcounter +=1
    ouf.write('Case #%d: %s\n' % (printcounter,a))

def solvetest():
    a,b,k  = map(int, inf.readline().split())
    ans = 0
    for i in range(a):
        for j in range(b):
            if i&j < k:
                ans += 1
    printstr(str(ans))
testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()

