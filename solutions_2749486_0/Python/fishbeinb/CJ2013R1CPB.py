#Code Jam 2013 - R1C - PB
#Ben Fishbein
#5/13
#Pogo
#Reach x,y under constraints
#https://code.google.com/codejam/contest/2437488/dashboard#s=p1
##can solve small thats what I'm doing

from math import *
into = open('CJ2013R1CPB.in')
out = open('CJ2013R1CPB.out', 'w')

lines = []
lines = into.readlines()


for z in range(int(lines[0])):
    info = lines[z+1].split()
    
    x = int(info[0])
    y = int(info[1])

    path = ""

    for p in range(abs(x)):
        if (x > 0):
            path = path + "WE"
        else:
            path = path + "EW"
    for p in range(abs(y)):
        if (y > 0):
            path = path + "SN"
        else:
            path = path + "NS"
    print  path, "path", z+1, x, y
    out.write("Case #" + str(z+1) + ": " + path + "\n")
out.close()


