__author__ = 'archeg'


def solve(startKeys, treasureData): # TreasureData (treasureN, keyToOpenTreasure, [ListOfKeysInTreasure])

    beenTo = []
    def openChest(key, chest, currentKeys, openedChests):
        currentKeys.remove(key)
        openedChests.append(chest)
        for key in [treasures for nChest, key, treasures in treasureData if nChest == chest][0]:
            currentKeys.append(key)
        return currentKeys

    def closeChest(key, chest, currentKeys, openedChests):
        currentKeys.append(key)
        openedChests.remove(chest)
        for t in [treasures for nChest, key, treasures in treasureData if nChest == chest][0]:
            currentKeys.remove(t)
        return currentKeys

    def doSearch(currentKeys, openedChests, treasureData, orderOfOpenedChests):

        lst = sorted(openedChests) + [" "] + sorted(currentKeys)
        if lst not in beenTo:
            beenTo.append(lst)
        else:
            return None

        if len(openedChests) == len(treasureData):
            return openedChests

        if currentKeys == []:
            return None

        # ------------ Do some pruning
        # Check whether there is enough keys for us
        neededKeys = [keyToOpenTreasure for treasureN, keyToOpenTreasure, treasures in treasureData if treasureN not in openedChests]
        l = [treasures for treasureN, keyToOpenTreasure, treasures in treasureData if treasureN not in openedChests]
        availableKeys = currentKeys + [item for sublist in l for item in sublist]
        for key in availableKeys:
            if key in neededKeys:
                neededKeys.remove(key)
        if len(neededKeys) != 0:
            return None

        # Prune cases if there are some treasure that reqiures the key it has and we do not have and we cannot get it in another treasure
        neededKeys = [keyToOpenTreasure for treasureN, keyToOpenTreasure, treasures in treasureData if treasureN not in openedChests]
        for key in neededKeys:
            if key not in currentKeys:
                lockedTreasures = sorted([treasureN for treasureN, keyToOpenTreasure, treasures in treasureData if keyToOpenTreasure == key and treasureN not in openedChests])
                treasuresWithKey = sorted([treasureN for treasureN, keyToOpenTreasure, treasures in treasureData if key in treasures and treasureN not in openedChests])
                if  lockedTreasures == treasuresWithKey:
                    return None

        # Open all the chests that requires the same key they have - these are "free" chests
        freeKeysAndChestsOpened = []
        # for chestN, keyToOpen, innerKeys in treasureData:
        #     if keyToOpen in innerKeys and keyToOpen in currentKeys and chestN not in openedChests:
        #         freeKeysAndChestsOpened.append((chestN, keyToOpen))
        #         currentKeys = openChest(keyToOpen, chestN, currentKeys, openedChests)

        def closeTheFreeChestsAgain():
            for chestN, key in freeKeysAndChestsOpened:
                closeChest(key, chestN, currentKeys, openedChests)

        # ------------ Now search for the solution

        # import itertools
        # keysToChooseFrom = set(currentKeys)
        # possibleTreasures = []
        # keysOrder = []
        # for key in keysToChooseFrom:
        #     treasuresToOpen = [chestN for chestN, keyToOpen, innerKeys in treasureData if keyToOpen == key and chestN not in openedChests]
        #     if (treasuresToOpen != []):
        #         possibleTreasures.append(treasuresToOpen)
        #         keysOrder.append(key)
        #
        # if len(openedChests) == len(treasureData):
        #     return openedChests
        #
        # if possibleTreasures == []:
        #     return None
        #
        # # Generate all possible combinations
        # plan = sorted([zip(keysOrder, x) for x in itertools.product(*possibleTreasures)], key=lambda x: min([y[1] for y in x]))

        for chest, key, treasureKeys in treasureData:
        # for action in plan:
            if chest not in openedChests and key in currentKeys:
                #for key, chest in action:
                currentKeys = openChest(key, chest, currentKeys, openedChests)

                orderOfOpenedChests.append(chest)
                #print action
                res = doSearch(currentKeys, openedChests, treasureData, orderOfOpenedChests)#+ sorted([chest for key, chest in action]))
                if res != None:
                    return res
                orderOfOpenedChests.remove(chest)

                #for key, chest in action:
                currentKeys = closeChest(key, chest, currentKeys, openedChests)

        # Do not forget to close the "free" chests

        closeTheFreeChestsAgain()
        return None

    chestOrder = doSearch(startKeys, [], treasureData, [])

    return chestOrder

def run(tcNumberToRun = None):
    fi = open('treasure.in', 'r')
    input = fi.readlines()
    t = int(input[0]) # Number of test cases
    index = 1

    testCases = []
    for i in range(t):
        k, n = [int(x) for x in input[index].split()] #Number of keys I'm starting with, Number f chests I need to open
        index += 1
        startKeys = [int(x) for x in input[index].split()]
        index += 1
        data = []
        for j in range(n):
            line = [int(x) for x in input[index].split()]
            kj, nj, keys = line[0], line[1], []
            if nj != 0:
                keys = line[2:]
            data.append((j + 1, kj, keys)) #For each treasure: number of chest, it's key number and the keys that are inside
            index += 1
        testCases.append((k, n, startKeys, data))

    output = []
    tcNumber = 1

    if tcNumberToRun != None:
        testCases = [testCases[tcNumberToRun - 1]]
        print testCases[0]

    for k, n, startKeys, treasureData in testCases:
        print "Running %i" % tcNumber
        print startKeys
        print treasureData
        solution = solve(startKeys, treasureData)
        print solution
        if solution == None:
            stringgedSolution = "IMPOSSIBLE"
        else:
            stringgedSolution = " ".join([str(x) for x in solution])

        print "-----"
        output.append("Case #%i: %s\n" % (tcNumber, stringgedSolution))
        tcNumber += 1

    with open("treasure.out", 'w') as fo:
        fo.writelines(output)
    fo.close()

def test():
    import random
    testCases = []
    chestsData = []
    for i in range(200):
        keyNumber = 20
        keys = []
        for j in range(keyNumber):
            keys.append(int(random.random() * 199) + 1)
        chestsData.append((i + 1, keyNumber, keys))
    testCases.append((2, 200, [1, 2], chestsData))
    output = []
    tcNumber = 1
    for k, n, startKeys, treasureData in testCases:
        solution = solve(startKeys, treasureData)
        if solution == None:
            stringgedSolution = "IMPOSSIBLE"
        else:
            stringgedSolution = " ".join([str(x) for x in solution])

        output.append("Case #%i: %s\n" % (tcNumber, stringgedSolution))
        tcNumber += 1

    with open("treasure.out", 'w') as fo:
        fo.writelines(output)
    fo.close()

#for i in range(10, 25):
run()
#test()



