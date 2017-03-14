import math
from numpy import *
fp = open('D-small-attempt0.in', 'r')
fp2 = open('output.txt', 'w')

numCases = int(fp.readline())
print numCases
for mastercount in range(numCases):
    inpStr = fp.readline().split(" ")
    h = int(inpStr[0])
    w = int(inpStr[1])
    d = int(inpStr[2])
    px = -1
    py = -1
    data = []
    for hcount in range(h):
        data.append(fp.readline())
        for wcount in range(w):
            if data[hcount][wcount] == 'X':
                py = hcount-1
                px = wcount-1
    w -= 2
    h -= 2
    print px, py
    xmap = zeros([d*2+1, d*2+1])
    for x in range(0, d*2+1):
        for y in range(0, d*2+1):
            if ((x-d)%(w*2) == 0 or (x-d)%(w*2) == (w-px)*2 -1) and ((y-d)%(h*2) == 0 or (y-d)%(h*2) == (h-py)*2 - 1):
                xmap[y][x] = 1.0

    print xmap
    prevAngles = []
    count = 0
    for x in range(0, d*2+1):
        for y in range(0, d*2+1):
            if x != d or y != d:
                dx = x-d
                dy = y-d
                distsquared = dx*dx+dy*dy
                if xmap[y][x] == 1.0 and distsquared <= d*d:
                    a = math.atan2(y - d, x - d)
                    if not a in prevAngles:
                        prevAngles.append(a)
                        count += 1
    print "Case #"+str(mastercount+1)+": " + str(count)
    fp2.write("Case #"+str(mastercount+1)+": " + str(count)+"\n")
    
    
fp.close()
fp2.close()
