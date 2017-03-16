def stringSub(s, index, new):
    new = str(new)
    return s[0:index]+new+s[index+1:]
def score(x,y,xvalues,yvalues,index):
    if index>=len(x):
        return [xvalues,yvalues]
    newXvalues=[]
    newYvalues=[]
    if x[index]=="?":
        for v in xvalues:
            for i in range(0,10):
                newXvalues.append(stringSub(v,index,str(i)))
    else:
        newXvalues=xvalues
    if y[index]=="?":
        for v in yvalues:
            for i in range(0,10):
                newYvalues.append(stringSub(v,index,str(i)))
    else:
        newYvalues=yvalues
    return score(x,y,newXvalues,newYvalues,index+1)

def scoreL(x,y,xvalues,yvalues,index):
    print [xvalues,yvalues]
    if index>=len(x):
        return [xvalues,yvalues]
    newXvalues=[]
    newYvalues=[]
    if x[index]==y[index]=="?":
        for v in xvalues:
            newXvalues.append(stringSub(v,index,"9"))
            newXvalues.append(stringSub(v,index,"0"))
        for v in yvalues:
            newYvalues.append(stringSub(v,index,"9"))
            newYvalues.append(stringSub(v,index,"0"))
    elif x[index]=="?":
        yi=int(y[index])
        for v in xvalues:
            newXvalues.append(stringSub(v,index,int(yi)))
            if yi!=0:
                newXvalues.append(stringSub(v,index,int(yi-1)))
            if yi!=9:
                newXvalues.append(stringSub(v,index,int(yi+1)))
        newYvalues = yvalues
    elif y[index]=="?":
        xi=int(x[index])
        for v in yvalues:
            newYvalues.append(stringSub(v,index,int(xi)))
            if xi!=0:
                newYvalues.append(stringSub(v,index,int(xi-1)))
            if xi!=9:
                newYvalues.append(stringSub(v,index,int(xi+1)))
        newXvalues = xvalues
    else:
        newXvalues = xvalues
        newYvalues = yvalues
    return score(x,y,newXvalues,newYvalues,index+1)

def solve(x,y):
    L=len(x)
    print x,y 
    [xvalues,yvalues] = score(x,y,[x],[y],0)
    print [xvalues,yvalues]
    print "$$$"
    xvalues=map(int, xvalues)
    yvalues=map(int, yvalues)
    minDiff=100000000000000
    minX=10000000000000
    minY=10000000000000
    for x in xvalues:
        for y in yvalues:
            if abs(x-y)<minDiff:
                minDiff = abs(x-y)
                minX = x
                minY = y
            if abs(x-y)==minDiff and x<minX:
                minDiff = abs(x-y)
                minX = x
                minY = y
            if abs(x-y)==minDiff and x==minX and y<=minY:
                minDiff = abs(x-y)
                minX = x
                minY = y
    minX=str(minX)
    while len(minX)<L: minX="0"+minX
    minY=str(minY)
    while len(minY)<L: minY="0"+minY
    return str(minX) + " " + str(minY)

import sys
f = open(sys.argv[1], "r")
F = open(sys.argv[1]+".out", "w")
for case in range(int(f.readline())):
    [x,y]=f.readline().rstrip().split(" ")
    F.write("Case #%d: %s\n" % (case+1, solve(x,y)))

F.close()

