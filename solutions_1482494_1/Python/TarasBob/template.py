a_file = open('B-large.in')
numcases = int(a_file.readline())

for i in range(numcases):
    
    numlevels = int(a_file.readline())
    levels = []
    for j in range(numlevels):
        level = a_file.readline().split()
        levels.append(level)

    numstars = 0
    numgames = 0
    toobad = False
    while(len(levels) > 0 and toobad == False):
        got2points = False
        got1point = False
        for j in range(len(levels)):
            if levels[j][0] != 'x' and int(levels[j][1]) <= numstars:
                levels.pop(j)
                numstars += 2
                numgames += 1
                got2points = True
                break


        if got2points == False:
            for j in range(len(levels)):
                if levels[j][0] == 'x' and int(levels[j][1]) <= numstars:
                    levels.pop(j)
                    numstars += 1
                    got1point = True
                    numgames += 1
                    break
                
                
        #go for the one with the highest 2
        #find highest 2
        if got2points == False and got1point == False:
            highest2 = 0
            for j in range(len(levels)):
                if levels[j][0] != 'x' and int(levels[j][0]) <= numstars:
                    highest2 = max(highest2, int(levels[j][1]))

            if highest2 != 0:
                for j in range(len(levels)):
                    if levels[j][0] != 'x' and int(levels[j][0]) <= numstars and int(levels[j][1]) == highest2:
                        numstars += 1
                        levels[j][0] = 'x'
                        got1point = True
                        numgames += 1
                        break

        if got2points == False and got1point == False:
            toobad = True
            
    if toobad:
        print("Case #" + str(i + 1) + ": " + "Too Bad")
    else:   
        print("Case #" + str(i + 1) + ": " + str(numgames))
