def canCutPattern(pattern):
    w = len(pattern)
    h = len(pattern[0])
    for i in range(w):
        for j in range(h):
            # path out up & down
            hasUpAndDown = True
            for k in range(w):
                if pattern[k][j] > pattern[i][j]:
                    hasUpAndDown = False
            # path out left & right
            hasLeftAndRight = True
            for k in range(h):
                if pattern[i][k] > pattern[i][j]: ##############
                    hasLeftAndRight = False
            if not hasUpAndDown and not hasLeftAndRight:
                return "NO"
    return "YES"

def getPatternsFromFile(path = r'C:\Python32\google code jam 2013\qualification round\b_small.txt'):
    reader = open(path)
    lines = reader.readlines()
    reader.close()
    # Getting rid of excess newlines
    for i in range(len(lines)):
        if lines[i][-1] == "\n":
            lines[i] = lines[i][:-1]
    lines.reverse()
    numCases = int(lines.pop())
    output = ""
    for i in range(numCases):
        dimensions = lines.pop()
        curCase = []
        numLinesForCase = int(dimensions.split()[0])
        for j in range(numLinesForCase):
            curCase.append(lines.pop())
        for j in range(len(curCase)):
            curCase[j] = curCase[j].split()
            for k in range(len(curCase[j])):
                curCase[j][k] = int(curCase[j][k])
        output += "Case #" + str(i + 1) + ": " + canCutPattern(curCase) + "\n"
    output = output[:-1] # getting rid of newline at end
    print(output)
getPatternsFromFile()
