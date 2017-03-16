def Output(CaseN, res):
    outputLine = "Case #"+str(CaseN)+": "+str(res)
    fw.write(outputLine + "\n")


##################################
name = 'B-practice'
name = 'B-small'
#name = 'B-large'

f = open(name + '.in', 'r')
fw = open(name + '.out', 'w')
lines = f.readlines()
T = int( lines.pop(0) )

def quickSolve(X, Y):
    # move to X
    if X < 0:
        directsX = ['E', 'W']*abs(X)
    else:
        directsX = ['W', 'E']*abs(X)

    
    if Y < 0:
        directsY = ['N', 'S']*abs(Y)
    else:
        directsY = ['S', 'N']*abs(Y)


    if len(directsX) + len(directsY) > 500:
        print 'ALARMA!', X, Y, len(directsX), len(directsY)
    return ''.join(directsX) + ''.join(directsY)

for i in xrange(T):
    #print i
    X, Y = map( lambda x: int(x), lines.pop(0).split(' ') )   
    res = quickSolve(X, Y)
    Output(i+1, res)