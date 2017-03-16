#Code Jam 2013 - R1A - PA
#Ben Fishbein
#4/13
#Bullseye
#Find how large of a bullseye I can make
#https://code.google.com/codejam/contest/2418487/dashboard#s=p0
##just going for points
###solve large later

from math import *
into = open('CJ2013R1APB.in')
out = open('CJ2013R1APB.out', 'w')

lines = []
lines = into.readlines()
y = 0
while y < (int(lines[0])*2-1):
    a = lines[y+1].split()
    print a, "a"
    E = int(a[0])
    Ec = int(a[0])
    R = int(a[1])
    Total = 0
    Spend = 0
    y = y + 1
    b = lines[y+1].split()
    print b, "b"
    for x in range(len(b)):
        current = int(b[x])
        bigger = 0
        isBigger = True
        for z in b[x:]:
            bigger = bigger + 1
            if (int(z) > current):
                isBigger = False
                break
        if(isBigger):
            bigger = 0
            Total = Total + Ec * int(b[x])
            Ec = R
        else:
            if(Ec + R*bigger > E):
                if (R*bigger > E):
                    Spend = Ec
                else:
                    Spend = Ec + R - E
            Total = Total + Spend * int(b[x])
            Ec = Ec - Spend + R
        #print Total
    y = y + 1
    print  Total, "total"
    out.write("Case #" + str(y/2) + ": " + str(Total) + "\n")
out.close()
