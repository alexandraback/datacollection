import re
import math

inp=open("C-large.in","r")
outp=open("Cl_oupt.txt","w")
lines = inp.readlines()
inp.close()

def ans(r,c,s):
    if r==1:
        return [['.']*s+['*']*(c-s)]       
    elif s==1:
        x=[['.']+['*']*(c-1)]
        y=[['*']*c]
        return x+y*(r-1)
    elif s>=2*r and s!=2*r+1:
        x=[['.']*(s/r)+['*']*(c-s/r)]
        y=[['.']*(s/r+1)+['*']*(c-s/r-1)]
        z=[['.']*(s/r-1)+['*']*(c-s/r+1)]
        q=s%r
        if q!=1:
            return y*q+x*(r-q)
        elif r>2:
            return y*2+x*(r-3)+z
        else:
            print "Impossible",r,c,s
            return "Impossible"
    elif s%2==0 and s>=4:
        x=[['.']*2+['*']*(c-2)]
        y=[['*']*c]
        return x*(s/2)+y*(r-s/2)
    elif (s-3)/2>=3 and r>2:
        a=(s-3)/2
        x=[['.']*3+['*']*(c-3)]
        y=[['.']*2+['*']*(c-2)]
        z=[['*']*c]
        return x*3+y*(a-3)+z*(r-a)
    elif s==5 and r>=2 and s>=3 and False:
        x=[['.']*3+['*']*(c-3)]
        y=[['.']*2+['*']*(c-2)]
        z=[['*']*c]
        return x+y+z*(r-2),1
    elif s==7 and r>=3 and False:
        x=[['.']*3+['*']*(c-3)]
        y=[['*']+['.']+['*']*(c-2)]
        z=[['*']*c]
        return x*2+y+z*(r-3),2
    else:
        if s not in [2,3,5,7]:
            print "ERROR",r,c,s
        print "Impossible",r,c,s
        return "Impossible"

def check(A,r,c,m):
    count=0
    for i in A:
        for j in i:
            if j=="*":
                count+=1
    if count!=m:
        print A,r,c,m
        return False
    return True
    
def solve(r,c,m):
    if r>c:
        A=ans(c,r,r*c-m)
        if A=="Impossible":
            return A+"\n"
        if not check(A,c,r,m):
            print "INVALID"
        answer=""
        for i in range(r):
            word=""
            for j in range(c):
                if (i,j)==(0,0):
                    word+="c"
                else:
                    word+=A[j][i]
            word+="\n"
            answer+=word
        return answer
    else:
        A=ans(r,c,r*c-m)
        if A=="Impossible":
            return A+"\n"
        if not check(A,r,c,m):
            print "INVALID"
        answer=""
        for i in range(r):
            word=""
            for j in range(c):
                if (i,j)==(0,0):
                    word+="c"
                else:
                    word+=A[i][j]
            word+="\n"
            answer+=word
        return answer

k=int(lines.pop(0))

for i in range(k):
    a=re.sub("\n","",lines[i])
    a_inp=re.split(" ",a)
    outp.write("Case #"+str(i+1)+":\n")
    outp.write(solve(int(a_inp[0]),int(a_inp[1]),int(a_inp[2])))
outp.close()
