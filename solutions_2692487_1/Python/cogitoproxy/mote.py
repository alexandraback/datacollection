inputFile = open('pr1__.in','r')
outputFile = open('out','w')

totalCases = int(inputFile.readline().strip())

for caseNo in range(0,totalCases):
    mote,n = [int(a) for a in inputFile.readline().strip().split(' ')]
    moteValues = [int(a) for a in inputFile.readline().strip().split(' ')]
    moteValues = sorted(moteValues)
    optimalSolution = n
    additions = 0
    currentMote = -1
    while 1:
        currentMote+=1
        if currentMote == n:
            if additions<optimalSolution:
                optimalSolution = additions
            break
        if additions >= optimalSolution:
            break
        if additions + (n-currentMote) < optimalSolution:
            optimalSolution = additions + (n-currentMote)
        if mote > moteValues[currentMote]:
            mote += moteValues[currentMote]
            continue
        mote = (2*mote) - 1
        additions += 1
        currentMote -= 1
    print "Case #%d: %d" % (caseNo+1,optimalSolution)
    outputFile.write("Case #%d: %d\n" % (caseNo+1,optimalSolution))
outputFile.close()
