import sys

inFile = open(sys.argv[1], 'r')

numCases = int(inFile.readline())
for case in range(1, numCases + 1):
    numLevels = int(inFile.readline())
    levels = [map(int, inFile.readline().split()[::-1] + [0]) for i in range(numLevels)]
    levels.sort() # Sort by easiest two stars to get
    numStars = 0
    levelsCompleted = 0
    while levels:
        #print numStars, levels
        levelsCompleted += 1
        # We can complete a level with 2 stars
        if levels[0][0] <= numStars:
            numStars += 2 - levels[0][2]
            levels.pop(0)
        else:
            # Find other next level
            levels.sort(key=lambda i: (i[2], i[1], -i[0]))
            #print levels
            if levels[0][1] <= numStars and levels[0][2] == 0:
                levels[0][2] = 1
                numStars += 1
                levels.sort()
            else:
                result = "Too Bad"
                break
    else:
        result = levelsCompleted

    print 'Case #%d: %s' % (case, result)
