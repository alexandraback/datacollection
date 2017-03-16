f = open('C-small-attempt1.in', 'r')
f2 = open('output', 'w')

numCases = int(f.readline())
for c in range(0, numCases):
    n = int(f.readline())
    kids = f.readline().split()
    kids = [int(i) for i in kids]
    kids = [0] + kids
    currentMaxLength = 0
    remaining = set(range(1,n+1))
    while(len(remaining) != 0):
        start = remaining.pop()
        canBuildBack = True
        poss = []
        poss.append(start)
        while(True):
            nextKid = kids[poss[len(poss) - 1]]
            if(nextKid in poss):
                if(poss[0] == nextKid):
                    canBuildBack = False
                if(poss[0] != nextKid and poss[len(poss) - 2] != nextKid):
                    poss = []
                break
            else:
                poss.append(nextKid)
        # Now build back
        maxChainLength = 0
        if(len(poss) != 0 and canBuildBack):
            starts = []
            for x in range(1, len(kids)): 
                if(x not in poss and kids[x] == poss[len(poss) - 1]):
                    starts.append(x)
            for y in range(0, len(starts)):
                ch = []
                ch.append(starts[y])
                foundOne = True
                while(foundOne):
                    foundOne = False
                    for z in range(1, len(kids)):
                        if(z not in poss and z not in ch and kids[z] == ch[len(ch) - 1]):
                            ch.append(z)
                            foundOne = True
                if(len(ch) > maxChainLength):
                     maxChainLength = len(ch)
        if((len(poss) + maxChainLength) > currentMaxLength):
            currentMaxLength = (len(poss) + maxChainLength)
    f2.write("Case #" + str(c + 1) + ": " + str(currentMaxLength) + "\n")