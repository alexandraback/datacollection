def run():
    caseCount = int(input())
    for caseIndex in range(caseCount):
        inputValues = input().split(' ')
        patternLength = int(inputValues[0])
        complexity = int(inputValues[1])
        cleansAvailable = int(inputValues[2])

        if cleansAvailable < patternLength:
            print("Case #%d: IMPOSSIBLE" % (caseIndex+1)) # TODO: This isn't true, but shouldn't ever happen on small input?

        cleanStr = " ".join([str(x+1) for x in range(cleansAvailable)])
        print("Case #%d: %s" % (caseIndex+1, cleanStr))


run()
