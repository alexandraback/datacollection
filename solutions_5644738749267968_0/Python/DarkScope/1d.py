import sys
import os
T=int(raw_input())
for t in range(T):
    n=int(raw_input())
    A=[]
    B=[]
    A=raw_input().split(' ')
    for i in range(n):
        A[i]=float(A[i])
    B=raw_input().split(' ')
    for i in range(n):
        B[i]=float(B[i])
    A=sorted(A)
    B=sorted(B)
    ans_1=0
    ans_2=0
    map=[]
    used=[]
    aim=[]
    for i in range(n):
        map.append([])
        used.append([])
        for j in range(n):
            if A[i]>B[j]:
                map[i].append(1)
            else:
                map[i].append(0)
    for i in range(n):
        aim.append(-1)
    def find(x):
        for j in range(n):
            if (map[x][j]==1 and used[j]==0):
                used[j]=1
                if (aim[j]==-1 or find(aim[j])):
                    aim[j]=x
                    return True
        return False
    for i in range(n):
        for k in range(n):
           used[k]=0
        if find(i):
            ans_1=ans_1+1
    #print A
    #print B
    #print aim
    for i in range(n):
        now_a=A[i]
        flag=True
        for j in range(len(B)):
            if B[j]>now_a:
                del B[j]
                flag=False
                break
        if flag:
            del B[0]
            ans_2=ans_2+1
    print "Case #%d: %d %d"%(t+1,ans_1,ans_2)
        
