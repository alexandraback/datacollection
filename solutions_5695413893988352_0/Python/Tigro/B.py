T = int(input())
for testNo in range(T):
    coders, jammers = input().split()
    coders = list(coders)
    jammers = list(jammers)
    scoreLength = len(coders)

    ''' # Evening what can be evened
    for i in range(scoreLength):
        if coders[i] != '?' and jammers[i] == '?':
            jammers[i] = coders[i]

        elif coders[i] == '?' and jammers[i] != '?':
            coders[i] = jammers[i]'''

    questionMarksCoders = [elNo for elNo in range(len(coders)) if coders[elNo] == '?']
    questionMarksJammers = [elNo for elNo in range(len(jammers)) if jammers[elNo] == '?']

    minScore = 10**scoreLength
    maxScore = (10**(scoreLength+1)) - 1
    potentialCodersScores = []
    potentialJammersScores = []

    for i in range(minScore, maxScore):
        goodCoders = True
        for k in range(scoreLength):
            if str(i)[k+1] != coders[k] and coders[k] != '?':
                goodCoders = False
                break

        if goodCoders: potentialCodersScores.append(str(i)[1:])

        goodJammers = True
        for k in range(scoreLength):
            if str(i)[k+1] != jammers[k] and jammers[k] != '?':
                goodJammers = False
                break

        if goodJammers: potentialJammersScores.append(str(i)[1:])


    minDifference = 9999999999999999999999999
    minJammers = 9999999999999999999999999
    minCoders = 9999999999999999999999999

    for potentialCodersScore in potentialCodersScores:
        for potentialJammersScore in potentialJammersScores:
            if abs(int(potentialCodersScore) - int(potentialJammersScore)) < minDifference:
                minDifference = abs(int(potentialCodersScore) - int(potentialJammersScore))
                minCoders = potentialCodersScore
                minJammers = potentialJammersScore



    print("Case #%i: %s %s" % (testNo + 1, minCoders, minJammers))