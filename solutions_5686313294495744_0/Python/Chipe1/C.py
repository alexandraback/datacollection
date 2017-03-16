t=int(input())
for dfsfsd in range(t):
    n=int(input())
    L=[]
    for i in range(n):
        L.append(input().split())
    ans=0
    for i in range(1<<n):
        present=[False]*n
        first=set()
        second=set()
        for j in range(n):
            if 1<<j & i:
                present[j]=True
                first.add(L[j][0])
                second.add(L[j][1])
        #print(present)
        possib=True
        for j in range(n):
            if not present[j]:
                if L[j][0] not in first or L[j][1] not in second:
                    possib = False
        if possib:
            ans=max(ans,len([x for x in present if not x]))
    print("Case #{}: {}".format(dfsfsd+1, ans))
