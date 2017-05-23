filein = open('read.txt')
fileout = open('write.txt', 'w')

a = filein.readlines()
numTest = int(a.pop(0))

for Z in range(0, numTest):
    numLev = int(a.pop(0))
    levels = []
    stars = 0
    plays = 0
    
    for Y in range(0, numLev):
        temp = a.pop(0).split()
        temp1 = []
        for n in temp:
            temp1.append(int(n))
        levels.append(temp1)

    levelsComp = []
    for Y in range(0, len(levels)):
        levelsComp.append([])
        for X in levels[Y]:
            levelsComp[Y].append(X)
    for Y in range(0, len(levelsComp)):
        for X in range(0, len(levelsComp[Y])):
            levelsComp[Y][X] = 0

    levelsTrans = [[],[]]
    for Y in range(0, len(levels)):
        levelsTrans[0].append(levels[Y][0])
        levelsTrans[1].append(levels[Y][1])
    impossible = False
    while stars < 2*numLev:
        reset = False
        value1 = min(levelsTrans[1])
        pos1 = levelsTrans[1].index(value1)
        if value1 <= stars:
            levelsComp[pos1][1] = 1
            plays += 1
            stars += 1
            levelsTrans[1][pos1] = 9001
            if levelsComp[pos1][0] != 1:
                stars += 1
                levelsComp[pos1][0] = 1
                levelsTrans[0][pos1] = 9001
            reset = True
        if reset:
            continue
        value2cand = []
        pos2 = []
        for i in range(0, len(levelsTrans[0])):
            if levelsTrans[0][i] <= stars and levelsComp[i][0] != 1:
                value2cand.append(levelsTrans[1][i])
                pos2.append(i)
        if len(pos2) > 0:
            pos2value = pos2[value2cand.index(max(value2cand))]
            levelsComp[pos2value][0] = 1
            plays += 1
            stars += 1
            levelsTrans[0][pos2value] = 9001
            reset = True
        if reset:
            continue
        #value2 = min(levelsTrans[0])
        #if value2 < 9000 and value2 <= stars:
        #    pos = []
        #    for Y in range(0, len(levels)):
        #        if levels[Y][0] == value2 and levelsComp[Y][0] != 1:
        #            pos.append(levels[Y][1])
        #    if Z+1 == 5:
        #        print pos
        #    for Y in range(0, len(levels)):
        #        if levels[Y][0] == value2 and levels[Y][1] == max(pos):
        #            plays += 1
        #            stars += 1
        #            levelsComp[Y][0] = 1
        #            levelsTrans[0][Y] = 9001
        #            reset = True
        #        if reset:
        #            break
        #    if reset:
        #        continue
                
            
        #for Y in range(0, len(levels)):
        #    if levels[Y][1] <= stars and levelsComp[Y][1] != 1:
        #        if levelsComp[Y][0] == 0:
        #            stars += 1
        #            levelsComp[Y][0] = 1
        #        plays += 1
        #        stars += 1
        #       levelsComp[Y][1] = 1
        #        reset = True
        #    if reset:
        #        break
        #if reset:
        #    continue
        #for Y in range(0, len(levels)):
        #    if levels[Y][0] <= stars and levelsComp[Y][0] != 1:
        #        plays += 1
        #        stars += 1
        #        levelsComp[Y][0] = 1
        #        reset = True
        #    if reset:
        #        break
        #if reset:
        #    continue
        if stars < 2*numLev:
            impossible = True
        if impossible:
            break

    myString = 'Case #%d: '%(Z+1)
    if impossible:
        myString += 'Too Bad\n'
        fileout.write(myString)
        continue
    myString += str(plays)
    myString += '\n'
    fileout.write(myString)
            
filein.close()
fileout.close()
