import sys
from collections import deque

f = open( sys.argv[1] )
t = f.readline()

t = 1
line = f.readline()
while line != "":
    a0,n = [int(x) for x in line.split()]
    motes = [ int(x) for x in f.readline().split() ]
    motes.sort()
    output = ""

    a = a0

    minops = len(motes)
    poss = deque()
    poss.append( (a,0,0) )
    while len(poss) > 0:
        a,i,ops = poss.popleft()
        if ops > minops:
            continue
        if i == len(motes):
            if ops < minops:
                minops = ops
        else:
            if a > motes[i]:
                poss.append( (a+motes[i],i+1,ops) )
            elif a > 1:
                poss.append( (a+a-1,i,ops+1) )
            distToEnd = len(motes) - i
            poss.append( (a,len(motes),ops+distToEnd) )


    output = minops            
    print a0, motes
    print "Case #%s: %s"%(t,output)

    t += 1
    line = f.readline()
f.close()
