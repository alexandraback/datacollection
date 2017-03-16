
#inputFile = open("test.txt", "r")
inputFile = open("B-small-attempt0.in", "r")
outputFile = open("Round1CB.txt", "w")

numCases = int(inputFile.readline().strip())

for caseIndex in range(1, numCases + 1):
    goalX, goalY = map(int, inputFile.readline().strip().split(" "))
    currentX = 0
    currentY = 0
    jumpDistance = 1
    finalDirections = ""

    while currentX != goalX:
        if goalX > currentX:
            currentX += 1
            jumpDistance += 2
            finalDirections += "WE"
        else:
            currentX -= 1
            jumpDistance += 2
            finalDirections += "EW"

    while currentY != goalY:
        if goalY > currentY:
            currentY += 1
            jumpDistance += 2
            finalDirections += "SN"
        else:
            currentY -= 1
            jumpDistance += 2
            finalDirections += "NS"

    outputFile.write("Case #%d: %s\n" % (caseIndex, finalDirections))

inputFile.close()
outputFile.close()