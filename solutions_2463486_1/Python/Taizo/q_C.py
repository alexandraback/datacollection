
# -*- coding: cp932 -*-

import sys

def checkP(n):
    s = str(n)
    l = len(s)
    if l == 1: return True
    for i in range(int(l / 2)):
        if (s[i] != s[l-i-1]): return False
        
    return True

def makePSList(m):
    for i in range(m+1):
        if not checkP(i): continue
        n = i*i
        if checkP(n):
            print (str(n))


pslistfile = "pslist.txt"
f = open(pslistfile)
pslist = []
for line in f:
    pslist.append(int(line.rstrip()))
f.close()

inputfile = "C-large-1.in"
#inputfile = "sample.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')

tc_num = int(f.readline().rstrip())

#for i in pslist:
#    print(str(i))

for tc in range(tc_num):
    #for i in pslist:
    #    print ( str(i) )

    #makePSList(10000000)
    la = f.readline().rstrip().split()
    smin = int(la[0])
    smax = int(la[1])
    result = 0
    for ps in pslist:
        if (smin > ps): continue
        if (smax < ps): break
        #print ( str(ps))
        result = result + 1
    
    print("Case #" + str(tc+1) + ": " + str(result))

