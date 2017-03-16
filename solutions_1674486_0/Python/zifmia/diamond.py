# google code jam 2012 round 1c

# diamond inheritance

import copy

f = open("c:\\users\\James\\Downloads\\A-small-attempt1.in", "r")
#f = open("diamond.in","r")
fout= open("diamond.out", "w")

t = int(f.readline())

for t1 in xrange(t):
    n = int(f.readline())
    x = [0,]
    for n1 in xrange(n):
        s = map(int, f.readline().split() )
        x.append(s[1:])
    # x is a list of the sets of all classes that class #i inherits from directly

    collision = False
    for i in xrange(1,n+1):
        y = [False] * (n+1)
        x1 = x[i]    # set of parents to examine
        while x1:
            #print i, y
            newx = []
            for j in x1:
                if y[j]:
                    collision = True  #already been here
                    break
                else:
                    y[j] = True
                    newx += x[j]
            x1 = newx
        if collision:
            break

    answer = "Case #%d: " % (t1+1)
    if collision:
        answer += "Yes"
    else:
        answer += "No"
    answer += "\n"
        
    print answer,
        
    fout.write( answer )
fout.close()
        
