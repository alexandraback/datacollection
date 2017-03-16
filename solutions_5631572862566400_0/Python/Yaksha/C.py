
def solveEndedLoops(endedLoops):
    longestList = 0
    reverseEndedLoops = [x[::-1] for x in endedLoops]

    for (index, item) in enumerate(endedLoops):
        if len(item) > longestList:
            longestList = len(item)

        for (index2, item2) in enumerate(reverseEndedLoops):
            if index == index2:
                continue

            if len(item) + len(item2) - 1 < longestList:
                continue

            if item[-1] in item2:
                pos = item2.index(item[-1])
                newlist = item + item2[pos+1:]
            else:
                newlist = item + item2

            if len(newlist) < longestList:
                continue

            if len(newlist) == len(set(newlist)):
                if len(newlist) > longestList:
                    longestList = len(newlist)

    return longestList


def solveloops(n, BFF):
    BFF = [-1] + BFF

    circularLoops = []
    endedloops = []
    closedPairs = []
    for i in range(1, len(BFF)):
        loop = [i]
        next = BFF[i]
        while True:
            if len(loop) == 2 and next == loop[0]:
                closedPairs.append(loop)
                break

            if len(loop) > 2 and next == loop[0]:
                circularLoops.append(loop)
                break

            if len(loop) > 2 and next == loop[-2]:
                endedloops.append(loop)
                break

            if next in loop:
                break

            loop.append(next)
            next = BFF[next]

    maxClosedPairs = len(closedPairs)

    if circularLoops:
        maxCircurlarLoops = max([len(x) for x in circularLoops])
    else:
        maxCircurlarLoops = 0

    maxEndedLoops = solveEndedLoops(endedloops)

    print(closedPairs)
    print(circularLoops)
    print(endedloops)
    return max([maxClosedPairs, maxCircurlarLoops, maxEndedLoops])


FILENAME = "C-small-attempt2"


with open(FILENAME + ".in") as infile:
    with open(FILENAME + ".out", 'w') as outfile:
        numCases = int(infile.readline())

        for i in range(numCases):
            numKids = int(infile.readline())

            bffs = infile.readline().split()
            bffs = [int(x) for x in bffs]

            outfile.write("Case #%d: %s\n" % (i + 1, solveloops(numKids, bffs)))
