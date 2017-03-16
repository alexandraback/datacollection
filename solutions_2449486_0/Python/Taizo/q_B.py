
# -*- coding: cp932 -*-

import sys



inputfile = "B-small-attempt1.in"
#inputfile = "sample.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')

tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    mn = f.readline().split()
    m = int(mn[0])
    n = int(mn[1])
    t = [[0 for j in range(n)] for i in range(m)]
    
    for i in range(m): 
        line = f.readline().rstrip()
        la = line.split()
        for j in range(n):
            t[i][j] = int(la[j])
            
    mmax = [0 for i in range(m)]
    nmax = [0 for i in range(n)]  
    for i in range(m):
        for j in range(n):
            if t[i][j] > mmax[i]: mmax[i] = t[i][j]  

    for i in range(n):
        for j in range(m):
            if t[j][i] > nmax[i]: nmax[i] = t[j][i]  

            
    result = True
    for i in range(m):
        for j in range(n):
            #print ("chk " + str(i) + ":" + str(j))
            # left right
            if t[i][j] == nmax[j]:
                continue 
            #print ("lr NG")
            # up down
            if t[i][j] == mmax[i]:
                continue 
            #print ("ud NG")
            result = False
            #print (str(i) + ":" + str(j) + "," + str(result))
            break
        if not result: break


    resultStr = ""
    if result: resultStr = "YES"
    else: resultStr = "NO"
        
    print("Case #" + str(tc+1) + ": " + resultStr)

