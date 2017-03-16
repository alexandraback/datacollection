import sys

def facto(num):
    re=1
    for a in range(0,num):
        re*=(a+1)
    return re

caseN=int(input())
for i in range(1,caseN+1):
    k, c, s=map(int,sys.stdin.readline().split())
    if(c*s<k):
        print("Case #%d: IMPOSSIBLE"%(i))
        continue

    ansN=k//c
    if(k%c):
        ansN+=1

    ans=[]
    for z in range(0,ansN):
        tg=c*(z+1)
        if(tg>k):
            tg=k
        puz=0
        if(c>k):
            c=k
        for x in range(0,c):
            if(x==0):
                puz+=(tg-x)*(k**0)
            else:
                puz+=(tg-x-1)*(k**x)
        ans.append(puz)

    sys.stdout.write("Case #%d:"%(i))
    for x in range(0,ansN):
        sys.stdout.write(" %d"%(ans[x]))
    print()
