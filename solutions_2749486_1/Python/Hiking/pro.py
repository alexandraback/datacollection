#!/usr/bin/python
import sys

f_input = open(sys.argv[1])


LIMIT = 13
def Huristic(startx, starty):

    stepnum=1
    while (True):
        stepnum += 1
        ansstring = ""
        nowx, nowy = startx, starty
        for nowstep in xrange(stepnum, 0, -1):
            ## decide direction ##
            distances = [nowx, nowy, -nowx, -nowy]
            direction = distances.index(max(distances))

            if (direction == 0):
                nowx -= nowstep
                ansstring += "E"
            elif (direction == 1):
                nowy -= nowstep
                ansstring += "N"
            elif (direction == 2):
                nowx += nowstep
                ansstring += "W"
            elif (direction == 3):
                nowy += nowstep
                ansstring += "S"
        #print ansstring[::-1]
        if(nowx==0 and nowy ==0): return ansstring[::-1]

                
        


    
#SIZE = 100
#MAP = [[0 for i in xrange(SIZE*2+1)] for i in xrange(SIZE*2+1)]
def WFS(nowstep, nowx, nowy, nowstring):
    #print nowstep
    if nowx <= 100 and nowx >= -100 and nowy <= 100 and nowy >= -100:
        MAP[nowx+SIZE][nowy+SIZE] = nowstring
    
    if (nowstep == LIMIT):
        return
    else:
        nowstep += 1
        WFS(nowstep, nowx+nowstep, nowy, nowstring+"E")
        WFS(nowstep, nowx-nowstep, nowy, nowstring+"W")
        WFS(nowstep, nowx, nowy+nowstep, nowstring+"N")
        WFS(nowstep, nowx, nowy-nowstep, nowstring+"S")

            
linenums = int(f_input.readline().rstrip())
#WFS(0, 0, 0, "")
# for i in xrange(linenums):
#     targx, targy = map(int, f_input.readline().rstrip().split(" "))
#     sys.stdout.write("Case #"+str(i+1)+": "+str(MAP[targx+SIZE][targy+SIZE])+"\n")

for i in xrange(linenums):
    targx, targy = map(int, f_input.readline().rstrip().split(" "))
    sys.stdout.write("Case #"+str(i+1)+": "+Huristic(targx, targy)+"\n")


