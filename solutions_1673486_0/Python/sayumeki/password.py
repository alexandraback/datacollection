import sys, os

infile = open('A-small-attempt0.in', 'r')
output = open('password.out', 'w')

def doProblem(inLine1, inLine2):
    things = inLine1.split()
    a = int(things[0]) #characters typed
    b = int(things[1]) #password length

    p2 = inLine2.split()
    p = []
    for px in p2:
        p.append(float(px))
    #print p

    probRem = 1.0 # probability remaining
    
    expTyping = 0
    expBack = []
    expEnter = 2 + b
    for i in range(0, a):
        expBack.append(0)

    #print expBack

    for c in range(0, a):
        miss = (1 - p[c]) * probRem #prob of mistake on this character
        expTyping += miss * ((b + 1) + 1 + (b - a))
        for bs in range(0, a):
            if (a - bs - 1) <= c:
                #print "G " + str(c) + " " + str(bs) + " " + str((bs+1)*2 + (b-a) + 1)
                expBack[bs] += miss * ((bs+1)*2 + (b-a) + 1)
            else :
                #print "B " + str(c) + " " + str(bs) + " " + str((bs+1)*2 + (b-a) + 1 + b + 1)
                expBack[bs] += miss * ((bs+1)*2 + (b-a) + 1 + b + 1)
                
        probRem = probRem - miss

    expTyping += probRem * (b - a + 1)
    for bs in range(0, a):
        #print str((bs+1)*2 + (b-a) + 1)
        expBack[bs] += probRem * ((bs+1)*2 + (b-a) + 1)
    
    #print expTyping
    #for i in range(0, a):
    #    print expBack[i]
    #print expEnter

    expBackMin = -1
    for num in expBack:
        if expBackMin == -1 or num < expBackMin:
            expBackMin = num    
    
    return str(min(expTyping, expBackMin, expEnter) )

def println(line):
    print line
    output.write(line + "\n")

lines = infile.readlines()
cases = int(lines[0])
for i in range(0, cases):
    line1 = lines[i*2+1].strip()
    line2 = lines[i*2+2].strip()
    answer = float(doProblem(line1, line2))
    answerString = '%.6f' % answer
    println("Case #" + str(i+1) + ": " + answerString)
    
infile.close()
output.close()
