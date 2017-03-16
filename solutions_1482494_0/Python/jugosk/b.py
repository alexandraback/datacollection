#!/usr/bin/python
import sys


input = file('B-small-attempt3.in')
#input = file('input.txt')

lines = [x.split() for x in input.readlines()]

lineIndex = 0

cases = int(lines[lineIndex][0])
lineIndex += 1

for i in range(cases):
    #Read in
    numLevels = int(lines[lineIndex][0])
    lineIndex += 1
    levels = []
    for j in range(numLevels):
        levels.append(map(int, lines[lineIndex]))
        lineIndex += 1
    
    stars = 0
    plays = 0
    levelBeat = False
    gameLost = False
    while True:
        if len(levels) == 0:
            break
        
        #Check 2 stars possibility
        for level in levels:
            if len(level) == 2:
                if stars >= level[1]:
                    print "s:" + str(stars) + "p:" + str(plays) + " " + str(levels)
                    stars += 2
                    plays += 1
                    levelBeat = True
                    levels.remove(level)
                    break
        
        if levelBeat:
            levelBeat = False
            continue
        
        cost2star = -1
        max2starIndex = -1
        #Check 1 star finish possibility
        for index, level in enumerate(levels):
            if stars >= level[0]:
                if len(level) == 2:
                    if level[1] > cost2star:
                        cost2star = level[1]
                        max2starIndex = index
                else:
                    print "s:" + str(stars) + "p:" + str(plays) + " " + str(levels)
                    stars += 1
                    plays += 1
                    levelBeat = True
                    levels.remove(level)
                    break
                
        if levelBeat:
            levelBeat = False
            continue
        
        if max2starIndex > -1:
            print "s:" + str(stars) + "p:" + str(plays) + " " + str(levels)
            stars += 1
            plays += 1
            levels[max2starIndex] = levels[max2starIndex][1:]
            continue
        
            
        #Can't beat any levels :(
        gameLost = True
        break
    
    if gameLost:
        print "Case #%d: Too Bad" % (i+1)
    else:
        print "Case #%d: %d" % (i+1, plays)