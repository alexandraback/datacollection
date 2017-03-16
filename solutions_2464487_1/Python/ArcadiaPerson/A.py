import math

#area=pi* (r1**2 - r2**2)


def solveSum(base,iterations):
    answer=base*iterations
    nextAns=iterations*(iterations-1)*2
    return answer+nextAns
    


def solveCase(paint,radius):
    rings=0
    paintNeeded=(radius+1)**2 - (radius**2)
    if paintNeeded>paint:
        return "0"
    minimum=1
    maximum=10**20
    while True:
        
        middle=math.floor((minimum+maximum)/2)
        nextTry=solveSum(paintNeeded,middle)
        if nextTry>paint:
            maximum=middle-1
        elif nextTry<=paint:
            minimum=middle+1
            lastTry=solveSum(paintNeeded,middle+1)
            if lastTry>paint:
                return str(int(minimum-1))

    

X=open("algr.in")
z=open("output.txt","w")
case=0
cases=int(X.readline())
while case<cases:
    case+=1
    print case
    currentline=X.readline().rstrip().lstrip().split()
    paint=int(currentline[1])
    first=int(currentline[0])
    z.write("Case #"+str(case)+": "+solveCase(paint,first)+"\n")
z.close()
