from IOManager import formatInput, readInput, writeOutput

def solve(data):
    cases = formatInput(data,[1,1,1])
    results = []
    
    for case in cases:
        blocks = int(case[0][0])
        weightsN1 = sorted([float(s) for s in case[1][0].split(" ")])
        weightsN2 = sorted([float(s) for s in case[1][0].split(" ")],reverse=True)
        weightsK1 = sorted([float(s) for s in case[2][0].split(" ")])
        weightsK2 = sorted([float(s) for s in case[2][0].split(" ")])
        
        nDWScore = 0
        for _ in range(blocks):
            if weightsN1[-1] < weightsK1[-1]:
                weightsN1.pop(0)
                weightsK1.pop(-1)
            else:
                weightsN1.pop(-1)
                weightsK1.pop(-1)
                nDWScore += 1
            
        nOWScore = 0
        
        for i in range(blocks):
            nWeight = weightsN2[i]
            
            index = -1
            for j in range(len(weightsK2)):
                if weightsK2[j] > nWeight:
                    index = j
                    break
            
            if index == -1:
                weightsK2.pop(0)
                nOWScore += 1
            else:
                weightsK2.pop(index)
                
        results.append(str(nDWScore) + " "  + str(nOWScore))
        
    return results

question = "D"
roundNumber = "1"
name = "small-attempt0"

inputName = question + "-" + name + ".in"
outputName = question + "-" + name + ".out"

testCases, data = readInput(inputName)
writeOutput(solve(data),outputName)


    