import sys
caseN=int(input())
for i in range(1,caseN+1):
    inp=input()

    flipCount=0
    for j in range(1,len(inp)):
        if(inp[j-1] != inp[j]):
            flipCount +=1
    if(inp[-1] == '-'):
        flipCount +=1
    print("Case #%d: %d"%(i,flipCount))
