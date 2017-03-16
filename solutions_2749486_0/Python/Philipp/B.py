from math import *
def probB():
    f=open('input.txt','r')
    new=open('answer.txt','w')
    for tc in xrange(1, int(f.readline())+1):
        # Get input
        line1=f.readline()
        array=line1.split(" ")
        X=int(array[0])
        Y=int(array[1])
        solution=solve(X,Y)
        new.write('Case #%d: %s\n' % (tc, solution))


def solve(X,Y):
    solution=""
    x=0
    y=0
    n=1
    while (abs(x-X)>=n):
        if x>X:
            x-=n
            solution+="W"
        else:
            x+=n
            solution+="E"
        n+=1
    while (abs(y-Y)>=n):
        if y>Y:
            y-=n
            solution+="S"
        else:
            y+=n
            solution+="N"
        n+=1

    while (x!=X):
        diff=x-X
        if (diff>0):
            solution+=diff*"EW"
            x=X
            n+=diff
        else:
            solution+=abs(diff)*"WE"
            x=X
            n+=abs(diff)
    while (y!=Y):
        diff=y-Y
        if (diff>0):
            solution+=diff*"NS"
            y=Y
            n+=diff
        else:
            solution+=abs(diff)*"SN"
            y=Y
            n+=abs(diff)
    return solution
    
