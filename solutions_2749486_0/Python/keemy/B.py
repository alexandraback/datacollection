from math import *

fu=open('B-small-attempt1.in','r')
pro=(fu)

out=''


N=int(pro.readline())

memo={}
def prob(X,Y,n=1,curX=0,curY=0):
    if curX==X and curY==Y:
        return ""
    else:
        a1="N"+prob(X,Y,n+1,curX,curY+n)
        a2="S"+prob(X,Y,n+1,curX,curY-n)
        a3="E"+prob(X,Y,n+1,curX+n,curY)
        a4="W"+prob(X,Y,n+1,curX-n,curY)
        cur=a1
        if len(cur)>len(a2):
            cur=a2
        if len(cur)>len(a3):
            cur=a3
        if len(cur)>len(a4):
            cur=a4
        
def probs(Y,X):
    temp=''
    while X<0:
        temp+="NS"
        X+=1
    while X>0:
        temp+="SN"
        X-=1
    while Y<0:
        temp+="EW"
        Y+=1
    while Y>0:
        temp+="WE"
        Y-=1
    return temp

for n in range(N):
    rawr= pro.readline().split()

    X =int(rawr[0])
    Y= int(rawr[1])

    out=out + 'Case #%d: '%(n+1) + str(probs(X,Y)) + '\n'

print out

f=open('output','w')
f.write(out)
f.close()
fu.close()


