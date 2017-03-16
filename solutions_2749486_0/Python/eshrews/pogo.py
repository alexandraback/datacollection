#!/usr/bin/python

import fileinput

case = 1
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue

    ll = line.split()
    x = int(ll[0])
    y = int(ll[1])
    oy = y

    #print x, y

    ax = abs(x)
    ay = abs(y)

    xysum = ay + ax

    dist = 1
    while(xysum - dist >= 0):
        xysum -= dist
        dist += 1

    if(abs(xysum-dist) < xysum):
        dist += 1

    numl = range(1,dist)
    numl.reverse()
    resl = ["N"] * len(numl)
        
    for i, n in enumerate(numl):
        if ax >= n:
            ax -= n
            if(x < 0):
                x += n
                resl[i] = "W"
            else:
                x -= n
                resl[i] = "E"
        else:
            ay -= n
            if(oy < 0):
                y += n
                resl[i] = "S"
            else:
                y -= n

    resl.reverse()
    #print resl
    #print ax, ay
    ay = abs(ay)
    
    if(y < 0) :
        resl.extend(["NS"]*ay)
    elif(y > 0):
        resl.extend(["SN"]*ay)

    if(x < 0) :
        resl.extend(["EW"]*ax)
    elif(x > 0):
        resl.extend(["WE"]*ax)

    result = "".join(resl)
    print "Case #{0}: {1}".format(linenum, result)

