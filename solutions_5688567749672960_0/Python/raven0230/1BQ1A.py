from math import *

def start(N):
    temp=ceil(log10(N))
    if temp==1:
        return 1,1
    else:
        A=10
        for i in range(2,temp):
            A+=10+(10**(i-1)-1)
        return A,10**(temp-1)

T=int(input())
for i in range(1,T+1):
    N=int(input())
    A,S=start(N)
    if N<=20:
        A=N
    else:
        S2=(N-1)//S*S+1
        A+=(N-1)//S+N-S2+1
    print("Case #{}: {}".format(i,A))


        
