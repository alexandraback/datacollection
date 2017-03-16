import sys

def isAllEmpty(lawn):
    if lawn==[]: return True
    for i in lawn:
        if i!=[]: return False
    return True

def removeRow(lawn, row):
    lawn.pop(row)
    return lawn

def removeCol(lawn, col):
    for k in range(0,len(lawn)):
        lawn[k].pop(col)
    return lawn

def checkRow(lawn, row, val):
    for i in range(0, len(lawn[0])):
        if lawn[row][i] != val:
            return False
    return True

def checkCol(lawn, col, val):
    for i in range(0, len(lawn)):
        if lawn[i][col] != val:
            return False
    return True

def getMinOfBorder(lawn):
    minH=200
    minH=min(minH,min(lawn[0]))
    minH=min(minH,min(lawn[-1]))
    minH=min(minH,min([lawn[i][0] for i in range(0,len(lawn))]))
    minH=min(minH,min([lawn[i][-1] for i in range(0,len(lawn))]))
    return minH

fin = open("inp.in","r")
fout = open("out.txt","w")
T = int(fin.readline())

for trial in range(1,T+1):
    N,M = map(int,fin.readline().replace('\n','').split(' '))
    lawn = []
    for i in range(N):
        line = map(int,fin.readline().replace('\n','').split(' '))
        lawn.append(line)
    if N==1 or M==1:
        ans="YES"
    else:
        globalMin=attempt=0
        
        while True:
            if isAllEmpty(lawn):
                ans="YES"
                break
            minH = getMinOfBorder(lawn)
            if minH<globalMin:
                ans="NO"
                break
            globalMin = minH
            removedSomething = False
            for row in range(0,len(lawn)):
                if checkRow(lawn,row,minH):
                    lawn = removeRow(lawn, row)
                    removedSomething=True
                    break
            if lawn==[]:
                ans="YES"
                break
            for col in range(0,len(lawn[0])):
                if checkCol(lawn,col,minH):
                    lawn = removeCol(lawn, col)
                    removedSomething=True
                    break
            if lawn==[]:
                ans="YES"
                break
            attempt+=1
            if removedSomething==True: attempt=0
            if attempt==2 and removedSomething == False:
                ans="NO"
                break
            
    fout.write( "Case #" + str(trial) + ": " + ans + "\n")

fin.close()
fout.close()