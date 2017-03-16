cases = int(raw_input())
for case in range(1, cases + 1):
    numBlocks = int(raw_input())
    blocksN = map(float, raw_input().split())
    blocksK = map(float, raw_input().split())
    blocksN.sort()
    blocksK.sort()

    cheatScore = 0    
    n = 0
    for k in blocksK:
        while n < numBlocks and blocksN[n] < k:
            n += 1
        if n == numBlocks:
            break
        cheatScore += 1
        n += 1
        
    k = 0
    kScore = 0
    for n in blocksN:
        while k < numBlocks and blocksK[k] < n:
            k += 1
        if k == numBlocks:
            break
        kScore += 1
        k += 1
    normalScore = numBlocks - kScore
    
    print("Case #{}: {} {}".format(case, cheatScore, normalScore))
