def backspace(probs, totlen):
    numbacks = 0
    bestev = 1000000000
    for numbacks in range(len(probs)):
        bestcase = (totlen - len(probs) + 2*numbacks + 1)
        worstcase = (totlen - len(probs) + 2*numbacks + 1) + totlen + 1
        bestprob = 1
        for i in range(len(probs) - numbacks):
            bestprob *= float(probs[i])
        worstprob = 1 - bestprob
        ev = bestprob * bestcase + worstprob * worstcase
        bestev = min(bestev, ev)
    
    return bestev
    

def giveup(probs, totlen):
    return totlen + 2
    


a_file = open('A-small-attempt0.in')
numcases = int(a_file.readline())

for i in range(numcases):
    
    param = a_file.readline()
    params = param.split()
    totchars = int(params[1])
    probstr = a_file.readline()
    strprobs = probstr.split()

    ev = min(giveup(strprobs, totchars), backspace(strprobs, totchars))   
    
    print("Case #" + str(i + 1) + ": " + str(ev))
