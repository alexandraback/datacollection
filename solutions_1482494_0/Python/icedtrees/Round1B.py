file = open("C:\CodeJam\\Round1ABsmall.in","r")
output = open("C:\CodeJam\\Round1ABsmall.txt","w")

cases = int(file.readline())

for case in range(1,cases+1):
    numberLevels = int(file.readline())
    levels = []
    semiComplete = []
    for level in range(numberLevels):
        levels.append(list(map(int,file.readline().split())))
    stars = 0
    attempts = 0
    while not (levels == [] and semiComplete == []):
        attempts += 1
        done = False
        for levelIndex in range(len(levels)):
            if levels[levelIndex][1] <= stars:
                stars += 2
                del levels[levelIndex]
                done = True
                break
        if done == True:
            continue

        for levelIndex in range(len(semiComplete)):
            if semiComplete[levelIndex][1] <= stars:
                stars += 1
                del semiComplete[levelIndex]
                done = True
                break
        if done == True:
            continue

        for levelIndex in range(len(levels)):
            if levels[levelIndex][0] <= stars:
                stars += 1
                semiComplete.append(levels[levelIndex])
                del levels[levelIndex]
                done = True
                break
        if done == True:
            continue
        attempts = "Too Bad"
        break

    output.write("Case #" + str(case) + ": " + str(attempts))
    if case != cases:
        output.write("\n")

file.close()
output.close()