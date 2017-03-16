def doCase(lines, caseNumber):
    KLS = lines[(caseNumber * 3) + 1]
    K = int(KLS[0])
    L = int(KLS[1])
    S = int(KLS[2])
    keyboard = lines[(caseNumber * 3) + 2][0]
    target = lines[(caseNumber * 3) + 3][0]
    
    # overlap is the point where the word starts to overlap itself (0 if no overlap)
    overlap = earliestOverlap(target)
    maxInstances = 0

    if (L <= S):
        if (overlap > 0):
            # if there is overlap then the max number is 1 instance plus the number of overlaps you can have
            maxInstances += 1
            remainingLength = S - L
            maxInstances += remainingLength / overlap
        else:
            # no overlap so just a simple division
            maxInstances = S / L
    else:
        # S is not long enough
        return 0.0

    if (validKeyboard(target, keyboard) == False):
        # the keyboard can't make up the word
        return 0.0
        
    # the probability of the word occuring once on it's own.
    probability = wordProbability(target, keyboard)
    secondaryProbability = wordProbability(target[overlap:], keyboard)
    
    return maxInstances - probability - ((maxInstances - 1) * secondaryProbability)
    
def earliestOverlap(word):
    for offset in range(1, len(word)):
        validOverlap = True
        for i in range(0, len(word) - offset):
            if (word[i] != word[i + offset]):
                validOverlap = False
                break
                
        if (validOverlap == True):
            return offset
        
    return 0
    
def validKeyboard(target, keyboard):
    for i in range(0, len(target)):
        letterFound = False
        for j in range(0, len(keyboard)):
            if (target[i] == keyboard[j]):
                letterFound = True
                break
        
        if (letterFound == False):
            return False
            
    return True
    
def wordProbability(word, keyboard):
    probability = float(1)
    
    for i in range(0, len(word)):
        letterCount = 0
        for j in range(0, len(keyboard)):
            if (word[i] == keyboard[j]):
                letterCount += 1
                
        letterProbability = float(letterCount) / float(len(keyboard))
        probability = probability * letterProbability
        
    return probability

lines = [line.strip().split() for line in open('B-small-attempt2.in')]

out = open('output.txt', 'w')
for i in range(1, int(lines[0][0]) + 1):
    out.write("Case #" + str(i) + ": " + str(doCase(lines, i - 1)) + "\n")
out.close