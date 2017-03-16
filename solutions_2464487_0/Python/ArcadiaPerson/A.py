import math

#area=pi* (r1**2 - r2**2)
def solveCase(paint,radius):
    rings=0
    
    while True:
        nextPaintNeeded=((radius+1)**2 - radius**2)
        if nextPaintNeeded<=paint:
            rings+=1
            
            paint-=nextPaintNeeded
            radius+=2
        else:
            break
    return str(rings)

    

X=open("asmr.in")
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
