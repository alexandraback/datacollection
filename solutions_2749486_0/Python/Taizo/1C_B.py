
# -*- coding: cp932 -*-

import sys


#inputfile = "sample.in"
inputfile = "B-small-attempt0.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')

tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    line = f.readline().rstrip()
    la = line.split()
    X = int(la[0])
    Y = int(la[1])
    ans = ""

    if X < 0:
        for i in range(-X): ans = ans + "EW"
    elif X > 0:
        for i in range(X): ans = ans + "WE"

    if Y < 0:
        for i in range(-Y): ans = ans + "NS"
    elif Y > 0:
        for i in range(Y): ans = ans + "SN"


    
    print("Case #" + str(tc+1) + ": " + ans)

