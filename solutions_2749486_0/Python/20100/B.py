import math

def Combi(n,p):
    return math.factorial(n)/(math.factorial(p)*math.factorial(n-p))

T=int(input())

for i in range(T):
    l=input().split()
    ax=int(l[0])
    ay=int(l[1])
    g=0

    r=""
    if(True):
            if ax>0:
                r+="WE"*ax
            if ax<0:
                ax=ax*(-1)
                r+="EW"*ax
            if ay>0:
                r+="SN"*ay
            if ay<0:
                ay=ay*(-1)
                r+="NS"*ay
    
    print("Case #"+str(i+1)+": "+str(r))
