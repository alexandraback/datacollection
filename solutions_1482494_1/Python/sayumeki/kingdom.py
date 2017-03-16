import sys, os

infile = open('B-large.in', 'r')
output = open('kingdom.out', 'w')

def doProblem(levels):
    played = 0
    stars = 0
    totalStars = len(levels) * 2
    while True:
        oneStar = None
        if stars == totalStars:
            return str(played)

        doCont = False
        for level in levels:
            if level[0] < 0:
                if stars >= level[1]:
                    levels.remove(level)
                    stars += 1
                    played += 1
                    doCont = True
                    continue
            else:
                if stars >= level[1]:
                    levels.remove(level)
                    stars += 2
                    played += 1
                    doCont = True
                    continue
                if stars >= level[0]:
                    if (oneStar == None):
                        oneStar = level
                    elif (level[1] > oneStar[1]):
                        oneStar = level

        if (doCont):
            continue
        #print oneStar
        if (oneStar == None):
            return "Too Bad"
        oneStar[0] = -1
        played += 1
        stars += 1
    return "Too Bad"

def println(line):
    print line
    output.write(line + "\n")

lines = infile.readlines()
cases = int(lines[0])
lineNum = 1
for i in range(0, cases):
    levelCount = int(lines[lineNum])
    lineNum += 1
    levels = []
    for j in range(0, levelCount):
        thisline = lines[lineNum]
        lineNum += 1
        things = thisline.split()
        levels.append([])
        levels[j].append(int(things[0]))
        levels[j].append(int(things[1]))
   
    println("Case #" + str(i+1) + ": " + doProblem(levels))
    
infile.close()
output.close()
