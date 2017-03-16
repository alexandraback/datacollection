#inputFile = open("test.txt", "r")
inputFile = open("C-small-attempt0.in", "r")
outputFile = open("Round1CC.txt", "w")

numCases = int(inputFile.readline().strip())

for caseIndex in range(1, numCases + 1):
    numTribes = int(inputFile.readline().strip())
    tribeDetails = []
    for tribeIndex in range(numTribes):
        tribeDetails.append(map(int, inputFile.readline().strip().split(" ")))
    wall = {}
    currentDay = 0
    totalSuccessful = 0

    while tribeDetails: # every day
        #print "current day is:", currentDay
        #print "wall is", wall
        wallAdditions = {}
        for tribe in tribeDetails:
            #print tribe, "exists"
            if tribe[0] != currentDay:
                if tribe[0] < currentDay:
                    tribe[0] += 1
                continue
            #print "tribe", tribe, "attacks!"
            successful = False
            for wallSection in range(tribe[2], tribe[3] + 1):
                #print (wallSection not in wall or wall[wallSection] < tribe[4]), (wallSection + 0.5 not in wall or (wallSection != tribe[3] and wall[wallSection + 0.5] < tribe[4]))
                if (wallSection not in wall or wall[wallSection] < tribe[4]) or (wallSection != tribe[3] and (wallSection + 0.5 not in wall or wall[wallSection + 0.5] < tribe[4])): #defeated
                    if wallSection not in wallAdditions or wallAdditions[wallSection] < tribe[4]:
                        wallAdditions[wallSection] = tribe[4]
                    if wallSection != tribe[3] and ((wallSection + 0.5) not in wallAdditions or wallAdditions[wallSection + 0.5] < tribe[4]):
                        wallAdditions[wallSection + 0.5] = tribe[4]
                    successful = True
            #if successful:
                #print("attack successful!")
            totalSuccessful += successful


            tribe[2] += tribe[6]
            tribe[3] += tribe[6]
            tribe[0] += tribe[5]
            tribe[4] += tribe[7]
            tribe[1] -= 1

        for addition in wallAdditions:
            if addition not in wall or wall[addition] < wallAdditions[addition]:
                wall[addition] = wallAdditions[addition]

        tribeDetails = [detail for detail in tribeDetails if detail[1]]

        currentDay += 1

    outputFile.write("Case #%d: %d\n" % (caseIndex, totalSuccessful))

inputFile.close()
outputFile.close()