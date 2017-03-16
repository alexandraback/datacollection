from math import factorial

def findPointer(startLetter, endLetters):
    pointer = ""
    for endLetter in trainDict[startLetter]:
        if endLetter != startLetter:
            if pointer == "":
                pointer = endLetter
            else:
                return False
    return pointer

def reduceTrain(train):
    newTrain = train[0]
    for char in train[1:]:
        if char != newTrain[-1]:
            newTrain += char
    return newTrain
    
numLines = raw_input()
for case in range(1, int(numLines) + 1):
    # print case
    numTrains = raw_input()
    trains = raw_input().split(" ")
    # print map(reduceTrain, trains)
    trainDict = dict()
    middleLetters = set()
    for train in trains:
        train = reduceTrain(train)
        if train[0] in trainDict:
            trainDict[train[0]].append(train[-1])
        else:
            trainDict[train[0]] = [train[-1]]
        if len(train) > 2:
            for letter in train[1:-1]:
                if letter in middleLetters:
                    trainDict = None
                    break
                middleLetters.add(letter)
        if trainDict == None:
            break
    for letter in middleLetters:
        if trainDict != None and (letter in trainDict.keys() or letter in trainDict.values()):
            trainDict = None
            
    if trainDict == None:
        print "Case #{}: {}".format(case, 0)
        continue
    pointers = {}
    for startLetter in trainDict:
        pointer = findPointer(startLetter, trainDict[startLetter])
        if pointer == False:
            pointers = None
            break
        pointers[startLetter] = pointer
    # print "pointers:", pointers
    if pointers != None:
        groups = []
        pointToNothing = 0
        while pointers:
            i = 0;
            start = pointers.keys()[i]
            while start in pointers.values():
                i += 1
                if i == len(pointers):
                    start = None
                    break
                start = pointers.keys()[i]
            if start == None:
                groups = None
                break
            
            groups.append([])
            pointer = start
            while pointer != "":
                if pointer not in pointers:
                    pointToNothing += 1
                    break
                value = len(trainDict[pointer])
                if pointers[pointer] != "":
                    value -= 1
                groups[-1].append(value)
                lastPointer = pointer
                pointer = pointers[pointer]
                   
                del pointers[lastPointer]
        # print groups
        # if groups != None and pointToNothing <= 1:
        if groups != None:
            total = 1
            for group in groups:
                for item in group:
                    if item > 1:
                        total *= factorial(item)
            total *= factorial(len(groups))
            result = total
        else:
            result = 0
    else:
        result = 0
    print "Case #{}: {}".format(case, result)