def createChain(currentKid, previousChain, bffs):
    currentChain = previousChain + [currentKid]
    #print(currentChain)
    maxLength1 = 0
    maxLength2 = 0
    if previousChain:
        isBffOfRoot = currentKid==bffs[previousChain[0]-1]
    else:
        isBffOfRoot = False
    maxTimeSinceBff =-1 
    for kid in range(1,len(bffs)+1):
        if kid in currentChain:
            continue
        if bffs[kid-1] != currentKid:
            continue
        (l1,l2,time) = createChain(kid,currentChain,bffs)
        if time > maxTimeSinceBff:
            maxTimeSinceBff = time
        if l1 > maxLength1:
            maxLength2 = maxLength1
            maxLength1= l1
        elif l1 > maxLength2:
            maxLength2 = l1
    newTimeSinceBff = -1 if not isBffOfRoot and maxTimeSinceBff==-1 else maxTimeSinceBff +1
    #print(currentChain)
    result = (maxLength1+1,maxLength2,1 if isBffOfRoot else newTimeSinceBff)
    #print(result)
    return result

def solution(bffs):
    if len(bffs) < 3:
        return len(bffs)
    maxChainLength = 3
    for i in range(1,len(bffs)+1):
        twoChains = createChain(i,[],bffs)
        if twoChains[1]==0: newChainLength = twoChains[2]
        elif twoChains[2]==2: newChainLength = sum((twoChains[0],twoChains[1]))
        else: continue
        maxChainLength = max(newChainLength,maxChainLength)
    return maxChainLength

for i in range(1,int(input())+1):
    N = int(input())
    bffs = list(map(int,input().split(' ')))
    
    print('Case #{}: {}'.format(i,solution(bffs)))