table = {4: [2],5:[2],6:[2,3],7:[3],8:[4],9:[3,4]}
tableMax = 10
def solve(a,maxP):
    minTime = maxP
    if maxP<4:
        return minTime
    for d in table[maxP]:
        tempA = a[:]
        tempA[d]+=a[maxP]
        tempA[maxP-d]+=a[maxP]
        tempA[maxP]=0
        tempMaxP = maxP-1
        while tempA[tempMaxP]==0: tempMaxP-=1
        tempMinTime = a[maxP]+solve(tempA,tempMaxP)
        if minTime>tempMinTime: minTime = tempMinTime
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
