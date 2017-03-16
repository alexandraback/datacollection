from datetime import datetime

#Input
fName = raw_input('Enter Filename of Input:\n')
with open(fName) as f:
    inp = [line.rstrip() for line in f]
#Output
timestamp = datetime.now().strftime("%H.%M.%S")
out = open('c'+timestamp+'.out', 'w')

#Stuff
caseCount = int(inp[0])
for case in range(1,caseCount+1):
    out.write('Case #'+str(case)+':\n')
    #Problem
    line = inp[case].split()
    y = int(line[0]) #row count
    x = int(line[1]) #column count
    m = int(line[2]) #mine count
    b = x*y-m        #'safe' count
    #Rotate grid to portrait
    if y<x:
        y,x = x,y
        rot = True
    else:
        rot = False
    #Make grid
    a = [[False for i in range(x)] for j in range(y)]#True = safe
    #Solving
    #Eliminate all imposible combinations
    if b==1:
        do = 'nothing'
    #1 by x grid
    elif x==1:
        for blank in range(b):
            a[blank][0] = True
    elif (b<4 or b in (5,7)) or  (b%2!=0 and x==2):
        out.write('Impossible\n')
        continue
    #2 by x grid (or 4/6 free)
    elif x==2 or b in(4,6):
        for blank in range(b/2):
            a[blank][0] = True
            a[blank][1] = True
    #8 or 9 free
    elif b in (8,9):
        for i in range(3):
            for j in range(3):
                a[j][i] = True
        if b==8:
            a[2][2] = False
    #It fits into 2 and a bit cols
    elif b<y*2+2:
        for i in range(3):
           for j in range(3):
               a[j][i] = True
        b-=9
        if b%2==1:
            a[2][2] = False
            b += 1
        j = 3
        while b>1:
            a[j][0] = True
            a[j][1] = True
            j += 1
            b -= 2
    #3 by 3 or bigger
    else:
        a = [[True for i in range(x)] for j in range(y)]#Now Subtractive
        i,j = x-1,y-1
        while m>0 and i>1:
            while m>0 and j>1:
                a[j][i] = False
                j -= 1
                m -= 1
            if m==0:
                break
            j = y-1
            i -= 1
            a[j][i] = False
            m -= 1
            if m==0:
                break
            a[j][i] = True
            a[0][i+1] = False
            a[1][i+1] = False
            m -= 1
    if rot:
        a = zip(*a[::-1])
        y,x = x,y
    for j in range(y):
        row = ""
        for i in range(x):
            if j==0 and ((i==0 and not rot) or (i==x-1 and rot)):
                row += 'c'
            elif a[j][i]:
                row += '.'
            else:
                row += '*'
        out.write(row+'\n')
out.close()
