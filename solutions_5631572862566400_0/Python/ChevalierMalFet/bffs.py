inputF = open('C-small-attempt1.in', 'r')
output = open('C-small-attempt1.out', 'w')

def findBestCircle(bffs):
    maxCircleLen = 0
    stableChains = {}
    for i in range(len(bffs)):
        tagged = [0]*len(bffs)
        tagged[i] = 1
        circle = [i]
        while tagged[bffs[circle[-1]]] == 0 and len(circle) < 50:
            circle += [bffs[circle[-1]]]
            tagged[circle[-1]] = 1
        if circle[-2] == bffs[circle[-1]]:
            tup = tuple(circle[-2:])
            if tup in stableChains:
                if len(stableChains[tup]) < len(circle):
                    stableChains[tup] = circle
            else:
                stableChains[tup] = circle
        else:
            start = circle.index(bffs[circle[-1]])
            circleLen = len(circle[start:])
            if circleLen > maxCircleLen:
                maxCircleLen = circleLen

    # Figure out the best you can do with stable chains
    bestStable = 0
    for pair in stableChains:
        if len(stableChains[pair]) == 0:
            continue
        if (pair[1], pair[0]) in stableChains:
            lenMirrorChain = (len(stableChains[pair]) +
                              len(stableChains[(pair[1], pair[0])]) - 2)
            bestStable += lenMirrorChain
            stableChains[(pair[1], pair[0])] = []
        else:
            bestStable += len(stableChains[pair])
    
        
    return max(maxCircleLen, bestStable)

numCases = int(inputF.readline())

for i in range(numCases):
    numKids = int(inputF.readline())
    bffs = [int(x)-1 for x in inputF.readline().split()]
    bestCircle = findBestCircle(bffs)

    output.write('Case #' + str(i+1) + ': ')
    output.write(str(bestCircle) + '\n')

inputF.close()
output.close()
