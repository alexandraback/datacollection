def run():
    caseCount = int(input())
    for caseIndex in range(caseCount):
        result = 0
        startNumber = int(input())
        hasResult = False
        for c in str(startNumber):
            cVal = int(c)
            if (cVal != 0):
                hasResult = True
                break
        if not hasResult:
            print("Case #%d: INSOMNIA" % (caseIndex+1))
            continue

        valCounts = [0]*10
        while min(valCounts) == 0:
            result += startNumber
            for c in str(result):
                cVal = int(c)
                valCounts[cVal] += 1

        print("Case #%d: %d" % (caseIndex+1, result))


run()
