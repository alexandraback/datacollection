from functools import lru_cache
@lru_cache(maxsize=None)
def special_need(a,b):
    l = a//b
    if a%b==0:
        l-=1
    return l
tableMax = 1001
def solve(a,maxP):
    minTime = maxP
    for finalP in range(maxP-1,1,-1):
        special = 0
        for i in range(maxP,finalP,-1):
            if a[i]!=0:
                special += a[i]*special_need(i,finalP)
        total = finalP+special
        #print(finalP,total)
        if minTime>total: minTime = total
        if special>minTime: break
    return minTime
for t in range(int(input())):
    D = int(input())
    P = [int(s) for s in input().strip().split(" ")]
    a = [0 for i in range(tableMax)]
    for i in P:
        a[i]+=1
    maxP = tableMax-1
    while a[maxP]==0: maxP-=1
    print("Case #{0}: {1}".format(t+1,solve(a,maxP)))
