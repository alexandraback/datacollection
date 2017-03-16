with open('in.txt') as f:
    lines = f.readlines()

def getInts(line):
    return map(int, line.split())

currentLine = 0
def getLine():
    global currentLine
    currentLine += 1
    return lines[currentLine-1].strip()

# def canCreate(target, coins, c):
#     total = 0
#     for coin in coins:
#         total += c * coin
#     return total

numCases = int(getLine())
for caseNum in xrange(numCases):
    c, numExisting, targetVal = getInts(getLine())
    originalCoins = getInts(getLine())
    origIndex = 0

    assert originalCoins == sorted(originalCoins)

    coins = [1]  # we must have 1.
    if originalCoins[0] == 1:  # in case we had 1 (most likely)
        origIndex += 1


    maxVal = c * sum(coins)
    while maxVal < targetVal:
        if origIndex >= len(originalCoins) or maxVal + 1 < originalCoins[origIndex]:
            # we can't just introduct the next existing denomination
            # introduce the first value that we can't make as a denomination
            coins.append(maxVal+1)
        else:
            # we can continue to use the old currency as the next step
            coins.append(originalCoins[origIndex])
            origIndex += 1

        maxVal = c * sum(coins)

    # add the original coins even if not strictly required
    while origIndex < len(originalCoins):
        coins.append(originalCoins[origIndex])
        origIndex += 1


    # print '     coins', coins
    answer = len(coins) - len(originalCoins)
    print 'Case #{}: {}'.format(caseNum+1, answer)

