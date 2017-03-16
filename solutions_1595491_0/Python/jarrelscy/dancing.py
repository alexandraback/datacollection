import math
fp = open('B-small-attempt2.in', 'r')
fp2 = open('output.txt', 'w')
numCases = int(fp.readline())

for c in range(numCases):
    inStr = fp.readline()
    inListStr = inStr.split(" ")
    inListInt = []
    for s in inListStr:
        inListInt.append(int(s))
    numGooglers = inListInt[0]
    numSurp = inListInt[1]
    threshold = float(inListInt[2])
    numPassed = 0
    totalScores = []
    for d in range(numGooglers):
        totalScores.append(inListInt[3+d])
    for totalScore in totalScores:
        mod = totalScore % 3
        third = math.ceil(float(totalScore)/3)
        if mod == 0:
            print third, third, third
        elif mod == 1:
            print third, third-1, third-1
        elif mod == 2:
            print third, third, third-1
        print threshold, numSurp, totalScore
        
        if(third < threshold):
            if(numSurp > 0 and totalScore > 1 and mod != 1 and third >= threshold - 1):
                numSurp -= 1
                numPassed += 1
                print 'Passed S' 
        else:
            numPassed += 1
            print 'Passed'
    fp2.write("Case #"+str(c+1)+": " + str(numPassed)+"\n")
    
    
fp.close()
fp2.close()
