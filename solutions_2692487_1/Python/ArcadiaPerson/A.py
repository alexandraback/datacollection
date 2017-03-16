import math
X=open("alg.in")
z=open("output.txt","w")
case=0
cases=int(X.readline())


def copyList(oldList):
    newList=[0]*len(oldList)
    for index in range(0,len(oldList)):
        newList[index]=oldList[index]
    return newList


def db(number):
    return (number*2)-1

def absorbable(number,motes):
    answer=0
    newMotes=copyList(motes)
    newMotes.sort()
    for each in motes:
        if number>each:
            answer+=1
            number+=each
    return (answer,number)

def removeNMinimum(N,motes):
    newMotes=copyList(motes)
    newMotes.sort()
    newMotes=newMotes[N:]
    return newMotes
def recSolveCase(size,motes,depth):
    motes.sort()
    if case==10:
        print size,motes,depth
    if len(motes)==0:
        return 0
    originalMotes=copyList(motes)
    if depth>100:
        return 10000000000
    minimum=min(motes)
    if size>minimum:
        newMotes=copyList(motes)
        newMotes.remove(minimum)
        size+=minimum
        return recSolveCase(size,newMotes,depth+1)
    elif (size*2)-1>minimum:
        size=size*2
        size-=1
        return 1+recSolveCase(size,motes,depth+1)
    else:
        newSize=size
        numAbs=0
        for doublings in range(1,102):
            newSize=db(newSize)
            (newNumAbs,newSize)=absorbable(newSize,motes)
            numAbs=numAbs+newNumAbs
            motes=motes[newNumAbs:]
            if numAbs>=doublings:
                return doublings+recSolveCase(newSize,motes,depth+1)
        else:
            maximum=max(originalMotes)
            
            originalMotes.remove(maximum)
            return 1+recSolveCase(size,originalMotes,depth+1)

def solveCase(size,motes):
    if size==1:
        return str(len(motes))
    return str(recSolveCase(size,motes,0))

while case<cases:
    case+=1
    c=X.readline().rstrip().lstrip().split()
    size=int(c[0])
    motes=X.readline().rstrip().lstrip().split()
    for index in range(0,len(motes)):
        motes[index]=int(motes[index])
    print case
    z.write("Case #"+str(case)+": "+solveCase(size,motes)+"\n")
z.close()
