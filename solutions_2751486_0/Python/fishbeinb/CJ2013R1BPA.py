#Code Jam 2013 - R1C - PA
#Ben Fishbein
#5/13
#Consonants
#Find the number of substrings with a certain number of consecutive Consonants
#https://code.google.com/codejam/contest/2437488/dashboard#s=p0

from math import *
into = open('CJ2013R1CPA.in')
out = open('CJ2013R1CPA.out', 'w')

lines = []
lines = into.readlines()
y = 0
for x in range(int(lines[0])):
    info = lines[x+1].split()
    
    name = info[0]
    number = int(info[1])
    starts = 0
    startpos = True
    total = 0

    for y in range(len(name)-number+1):
        #print name[y], "name [y]"
        for z in range(number):
            if(name[y+z] == ('a') or name[y+z] == ('e') or name[y+z] == ('i') or name[y+z] == ('o') or name[y+z] == ('u')):
               # print name[y+z], "name [y+z]"
                startpos = False
                break
        if(startpos == True):
            total = total + (y+1-starts)*(len(name)-(y+number)+1)
           # print "total:", (y+1-starts)*(len(name)-(y+number)+1), "total over:", total 
            starts = y + 1
            #print starts, "a"
        startpos = True
    #print  total, "total"
    out.write("Case #" + str(x+1) + ": " + str(total) + "\n")
out.close()


