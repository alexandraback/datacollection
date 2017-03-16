

with open('in.txt') as f:
    lines = f.readlines()

numCases = int(lines[0])
for caseNum in xrange(1, numCases+1):
    shy = map(int, lines[caseNum].split()[1])

    numFriends = 0
    numStanding = 0
    for shyLevel in xrange(len(shy)):
        if numStanding < shyLevel:
            newFriends = shyLevel - numStanding
            numStanding += newFriends
            numFriends += newFriends
        numStanding += shy[shyLevel]


    answer = numFriends
    print 'Case #{}: {}'.format(caseNum, answer)

