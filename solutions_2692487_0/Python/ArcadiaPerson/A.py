import math
X=open("ams3.in")
z=open("output.txt","w")
case=0
cases=int(X.readline())


def copyList(oldList):
    newList=[0]*len(oldList)
    for index in range(0,len(oldList)):
        newList[index]=oldList[index]
    return newList

def recSolveCase(size,motes,depth):
    if len(motes)==0:
        return 0
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
        newMotes=copyList(motes)
        newMotes.remove(minimum)
        x1=1+recSolveCase(((size*2)-1),motes,depth+1)
        x2=1+recSolveCase(size,newMotes,depth+1)
        return min(x1,x2)

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
