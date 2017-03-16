inputFile = open("A-small-attempt0 (1).in", 'r')
outputFile = open("safetyOutSmall.txt", 'w')
numTests = int(inputFile.readline())



def getVals(conts):
    x = sum(conts)*1.0
    trips = []
    for i in range(len(conts)):
        trips += [[i, conts[i], 0.0]]
    sortByIndex(trips, 1)
    freeVotes = 1.0
    for i in range(len(trips)-1):
        currVal = trips[i][1]
        nextVal = trips[i+1][1]
        toImprove = (nextVal - currVal)/x
        if toImprove*(i+1) >= freeVotes:
            for j in range(i+1):
                trips[j][2] += freeVotes/(i+1)
            freeVotes = 0.0
            break
        else:
            for j in range(i+1):
                trips[j][2] += toImprove
            freeVotes -= toImprove*(i+1)
    if freeVotes > 0:
        for i in range(len(trips)):
            trips[i][2] += freeVotes/len(trips)
    sortByIndex(trips,0)
    print trips
    return trips

def sortByIndex(trips, k):
    for i in range(0, len(trips) - 1):
        swap_test = False
        for j in range(0, len(trips) - i - 1):
            if trips[j][k] > trips[j + 1][k]:
                trips[j], trips[j + 1] = trips[j + 1], trips[j]
            swap_test = True
        if swap_test == False:
            break

for i in range(numTests):
    line = inputFile.readline().split()
    numContestants = int(line[0])
    conts = []
    for k in range(numContestants):
        conts += [int(line[k+1])]
    vals = getVals(conts)
    outputFile.write('Case #' + str(i+1) + ': ')
    for k in range(len(vals)):
        outputFile.write(str(vals[k][2]*100) + ' ')
    outputFile.write('\n')

inputFile.close()
outputFile.close()




