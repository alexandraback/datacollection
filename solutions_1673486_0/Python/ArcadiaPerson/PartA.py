import math

def passWordProblem(typed,length,probRights):
    answer=length+2
    for each in range(1,len(probRights)):
        probRights[each]=probRights[each]*probRights[each-1]
    toType=length-typed
    for backSpaces in xrange(0,(typed/2)+1):
        rightCount=(2*backSpaces)+toType+1
        wrongCount=(2*backSpaces)+toType+2+length
        curProbRight=probRights[typed-backSpaces-1]
        rightCount=rightCount*curProbRight
        wrongCount=wrongCount*(1-curProbRight)
        current=rightCount+wrongCount
        if current<answer:
            answer=current
    return str(answer)
        
        

X=open("asm.in")
z=open("output.txt","w")
case=0
currentline=X.readline()
currentline=X.readline().split()
while currentline:
    case+=1
    print case
    typed=int(currentline[0])
    total=int(currentline[1])
    probs=map(float,X.readline().rstrip().lstrip().split())
    z.write("Case #"+str(case)+": "+passWordProblem(typed,total,probs)+"\n")
    currentline=X.readline().split()
z.close()
