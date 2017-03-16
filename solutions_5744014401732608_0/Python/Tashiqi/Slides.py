from math import *
T=int(input())
for t in range(T):
    B,M=map(int,input().split())
    if log(M)>(B-2)*log(2):
        print("Case #" +str(t+1)+ ": IMPOSSIBLE")
    else:
        print("Case #" +str(t+1)+ ": POSSIBLE")
        s=["1"]*(B-1)
        if M==2**(B-2):
            print("0"+"1"*(B-1))
        else:
            r="0"
            for i in range(B-2):
                if M%2==1:
                    r="1"+r
                else:
                    r="0"+r
                M//=2
            print("0"+r)
        for i in range(B-1):
            s[i]="0"
            print("0"+"".join(s))
