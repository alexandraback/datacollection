import math

def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = '%.7f' % res
    outputLine = casestr+status
    fw.write(outputLine + "\n")


def secWith(farmNum, S, C, F, X):
    return  S + X / (2.0 + farmNum*F)

def solveCookie(C_F_X):
    (C, F, X) = C_F_X
    #print C, F, X
    farmNum = 0
    previous = X / 2
    S = 0.0
    while True:
        current = secWith(farmNum, S, C, F, X)
        #print "Check:", farmNum, S, current
        if (previous < current):
            return previous
        S += C / (2.0 + farmNum * F)
        previous = current
        farmNum += 1

##################################
#name = 'b-practice'
#name = 'b-small'
name = 'b-large'

f = open(name + '.in', 'r')
fw = open(name + '.out', 'w')
lines = f.readlines()
T = int( lines.pop(0) )
for t in xrange(T):
    output(t, solveCookie( map( float, lines.pop(0).split(' ') ) ) )