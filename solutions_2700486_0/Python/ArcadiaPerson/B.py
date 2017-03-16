import math
X=open("bsm.in")
z=open("output.txt","w")
case=0


def occupied(point1,diamonds):
    x=point1.x
    y=point1.y
    for each in diamonds:
        if each==0:
            break
        newX=each.x
        newY=each.y
        if (x==newX and y==newY):
            return True
        if (newX+1==x and y==newY):
            return True
        if (newX-1==x and y==newY):
            return True
        if (x==newX and y==newY-1):
            return True
        if (x==newX and y==newY+1):
            return True
    return False

class Point(object):
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def getY(self):
        return self.y
    def getX(self):
        return self.x
    def __repr__(self):
        return "("+str(self.x)+","+str(self.y)+")"
class line(object):
    def __repr__(self):
        return "Slope= "+str(self.slope)+" Intercept= "+str(self.b)

def copyList(oldList):
    newList=[0]*len(oldList)
    for index in xrange(0,len(oldList)):
        newList[index]=oldList[index]
    return newList

def recSolveCase(incDiamonds,nextToFall,curLocation,myPoint):
    diamonds=copyList(incDiamonds)
    if nextToFall==len(diamonds):
        if occupied(myPoint,diamonds):
            return 1
        return 0
   
    if (curLocation.y==0):
        diamonds[nextToFall]=curLocation
        newFirstPoint=Point(0,12)
        return recSolveCase(diamonds,nextToFall+1,newFirstPoint,myPoint)
    nextPoint=Point(curLocation.x,curLocation.y-1)
    if not occupied(nextPoint,diamonds):
        if nextPoint.y==0:
            diamonds[nextToFall]=nextPoint
            newFirstPoint=Point(0,12)
            return recSolveCase(diamonds,nextToFall+1,newFirstPoint,myPoint)
        else:
            return recSolveCase(diamonds,nextToFall,nextPoint,myPoint)
    leftPoint=Point(nextPoint.x-1,nextPoint.y)
    rightPoint=Point(nextPoint.x+1,nextPoint.y)
    rightOcc=occupied(rightPoint,diamonds)
    leftOcc=occupied(leftPoint,diamonds)
    if leftOcc and rightOcc:
        diamonds[nextToFall]=curLocation
        newFirstPoint=Point(0,12)
        return recSolveCase(diamonds,nextToFall+1,newFirstPoint,myPoint)
    if leftOcc:
        return recSolveCase(diamonds,nextToFall,rightPoint,myPoint)
    if rightOcc:
        return recSolveCase(diamonds,nextToFall,leftPoint,myPoint)
    return (.5*(recSolveCase(diamonds,nextToFall,leftPoint,myPoint)))+(.5*(recSolveCase(diamonds,nextToFall,rightPoint,myPoint)))

def solveCase(diamonds,X,Y):
    myPoint=Point(X,Y)
    
    firstPoint=Point(0,12)
    return str(recSolveCase(diamonds,0,firstPoint,myPoint))

cases=int(X.readline())
while case<cases:
    case+=1
    c=X.readline().rstrip().lstrip().split()
    xc=int(c[1])
    diamondCount=int(c[0])
    yc=int(c[2])
    diamonds=[0]*diamondCount
    print case
    z.write("Case #"+str(case)+": "+solveCase(diamonds,xc,yc)+"\n")
z.close()
