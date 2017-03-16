def naomiFinalWarPoints(naomiBlocks, kenBlocks, gameCount):
    kenIter = 0
    for naomiIter in xrange(gameCount):
        naomiBlock = naomiBlocks[naomiIter]
        while kenBlocks[kenIter] < naomiBlock:
            kenIter += 1
            if kenIter == gameCount:
                return gameCount - naomiIter 
        kenIter += 1
        if kenIter == gameCount:
            return gameCount - naomiIter - 1

def naomiFinalDeceitfulWarPoints(naomiBlocks, kenBlocks, gameCount):
    return gameCount - naomiFinalWarPoints(kenBlocks, naomiBlocks, gameCount)

def parseBlockLine(line):
    return map(lambda x: float(x), line[0:-1].split(" "))
    
inp = open("D-small-attempt0.in", 'r')
outp = open("D-small-attempt0.out", 'w')

T = int(inp.readline())

for testCase in xrange(T):
    gameCount = int(inp.readline())
    naomiBlocks = parseBlockLine(inp.readline())
    kenBlocks = parseBlockLine(inp.readline())
    naomiBlocks.sort()
    kenBlocks.sort()
    outp.write("Case #{}: {} {}\n".format(testCase + 1, naomiFinalDeceitfulWarPoints(naomiBlocks, kenBlocks, gameCount), naomiFinalWarPoints(naomiBlocks, kenBlocks, gameCount)))
outp.close()
