
def outputField1(R, C, M):
    if (R == 1):
        fw.write( "*"*M + "."*(C-M-1)+"c"+ "\n")
    else:
        fw.write( "*\n"*M + ".\n"*(R-M-1) +"c"+ "\n")

def outputField2(R, C, M):
    halfM = M/2
    if R == 2:
        fw.write("*"*halfM + "."*(C - halfM) + "\n")
        fw.write("*"*halfM + "."*(C - halfM- 1 ) + "c\n")
    else:
        fw.write( "**\n"*halfM )
        fw.write( "..\n"*(R - halfM - 1) )
        fw.write( ".c\n" )


def outputFieldNormal(R, C, M):
    filledR = R - 2
    filledC = C - 2
    filledN = filledR * filledC
    restCells = filledR*2+filledC*2
    restMines = M - filledN

    if restMines < 0:
        #print R,C,M,restMines, filledR, 
        realFilledRows = M / (C-2)
        restMines = M % (C-2)
        for i in xrange(realFilledRows):
            fw.write( "*"*(C-2) + "..\n" )
        fw.write("*"*restMines + "."*(C-restMines) + "\n")
        for i in xrange(R - realFilledRows - 2):
            fw.write("."*C + "\n")    
        fw.write("."*(C-1) + "c\n")
    elif (restMines % 2 == 0):
        fullRows = min(restMines / 2, filledR)
        fullCols = restMines / 2 - fullRows
        for i in xrange(fullRows):
            fw.write( "*"*C + "\n" )
        for i in xrange(filledR - fullRows):
            fw.write( "*"*(C-2) + "..\n" )
        # last 2 rows
        fw.write( "*"*fullCols + "."*(C-fullCols) + "\n" )
        fw.write( "*"*fullCols + "."*(C-fullCols-1) + "c\n" )
    else:
        fullRows = min((restMines-1) / 2, filledR - 1)
        fullCols = (restMines-1) / 2 - fullRows
        if fullRows == filledR - 1:
            fullCols += 1
        else:
            fullRows += 1
        for i in xrange(fullRows):
            fw.write( "*"*C + "\n" )
        for i in xrange(filledR - fullRows - 1):
            fw.write( "*"*(C-2) + "..\n" )
        # last 3 rows!!!!
        fw.write( "*"*(C-3) + "...\n" )
        fw.write( "*"*fullCols + "."*(C-fullCols) + "\n" )
        fw.write( "*"*fullCols + "."*(C-fullCols-1) + "c\n" )        

def outputAll(R, C):
    for i in xrange(R-1):
        fw.write("*"*C + "\n")
    fw.write("*"*(C-1) + "c\n")


def output(t, R, C, M):
    casestr = "Case #" + str(t+1) +": "
    fw.write(casestr + "\n")
    N = R*C
    if C == 1 or R == 1:
        outputField1(R, C, M)
        return
    elif M == N - 1:
        outputAll(R, C)
        return
    elif M == N - 2 or M == N - 3:
        fw.write("Impossible"+ "\n")
        return
    elif C == 2 or R == 2:
        if M % 2:
            fw.write("Impossible"+ "\n")
        else:
            outputField2(R, C, M)
        return
    elif M == N - 4 or M == N - 6:
        outputFieldNormal(R, C, M)
        return
    elif M == N - 5 or M == N - 7:
        fw.write("Impossible"+ "\n")
        return
    else: # R,C >= 3 M <= N - 8 . Always possible
        outputFieldNormal(R, C, M)
        return

##################################
#name = 'c-practice'
#name = 'c-test'
name = 'c-small'
#name = 'c-large'

f = open(name + '.in', 'r')
fw = open(name + '.out', 'w')
lines = f.readlines()




T = int( lines.pop(0) )
for t in xrange(T):
    (R, C, M) = map( int, lines.pop(0).split(' ') )
    output(t, R, C, M)