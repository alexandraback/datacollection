
def runTest():
    f = open('/Users/bavetta/Desktop/code jam/stage1b/A-small-attempt4.in', 'r')
    numberOfTestCases = int(f.readline())
    
    for num, i in enumerate(range(numberOfTestCases)):
        testCase = f.readline()
        splitText = testCase.split()
        numberOfContestants = int(splitText.pop(0))
        contestantScores = [0] * numberOfContestants
        for i in range(numberOfContestants):
            contestantScores[i] = int(splitText.pop(0))

        scoreSum = float(sum(contestantScores))
        
        output = ["Case #"]
        output.append(str(num+1))
        output.append(": ")

        #find overachievers
        overSum = 0
        overachievers = [0] * numberOfContestants
        for x, contestant in enumerate(contestantScores):
            target = scoreSum*2/numberOfContestants
            out = (target - contestant)/scoreSum
            if(out < 0):
                overachievers[x] = 1
                overSum = overSum + contestant
            
        for x, contestant in enumerate(contestantScores):
            target = (scoreSum*2 - overSum)/(numberOfContestants-sum(overachievers))
            out = (target - contestant)/scoreSum
            if out < 0:
                out = 0
            output.append(str(out*100))
            
            if x < len(contestantScores) - 1:
                output.append(" ")

        output = ''.join(output)
        print(output)

runTest()
