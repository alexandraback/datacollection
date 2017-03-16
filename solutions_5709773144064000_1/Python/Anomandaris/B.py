from IOManager import formatInput, readInput, writeOutput

def solve(data):
    cases = formatInput(data,[1],[str])
    results = []
    
    for case in cases:
        
        c = float(case[0].split(" ")[0])
        f = float(case[0].split(" ")[1])
        target = float(case[0].split(" ")[2])
        
        time = 0.0
        rate = 2.0
        
        while True:
            
            noFarmTT = target/rate
            farmTT = (target/(rate+f))
            farmT = (c/rate)
            
            if noFarmTT < farmTT + farmT:
                time += noFarmTT
                break
            else:
                time += farmT
                rate += f
        
        results.append(str(time))
    
    return results

    
    
question = "B"
roundNumber = "1"
name = "large"

inputName = question + "-" + name + ".in"
outputName = question + "-" + name + ".out"

testCases, data = readInput(inputName)
writeOutput(solve(data),outputName)


    