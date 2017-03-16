import sys
import math

def readline(f):
    return f.readline().strip(' \r\n\t')

def readIntLine(f, hasSpace):
    if (hasSpace):
        return [int(x) for x in readline(f).split()]
    else:
        arr = []
        line = readline(f)
        for i in xrange(0, len(line)):
            arr.append(int(line[i]))
        return arr

def readFloatLine(f):
    return [float(x) for x in readline(f).split()]

def readCharLine(f, hasSpace):
    if (hasSpace):
        return readline(f).split()
    else:
        arr = []
        line = readline(f)
        for i in xrange(0, len(line)):
            arr.append(line[i])
        return arr

def readIntArr(f, row, col, hasSpace):
    arr = [[0] * col for x in xrange(row)] 
    for i in xrange(row):
        arr[i] = readIntLine(f, hasSpace)
    return arr

def readFloatArr(f, row, col):
    arr = [[0.0] * col for x in xrange(row)] 
    for i in xrange(row):
        arr[i] = readFloatLine(f)
    return arr

def readCharArr(f, row, col, hasSpace):
    arr = [[''] * col for x in xrange(row)] 
    for i in xrange(row):
        if (hasSpace):
            arr[i] = readline(f).split()
        else:
            line = readline(f)
            for j in xrange(0, col):
                arr[i][j] = line[j]
    return arr

################## SOLVE ######################
class Tree(object):
    def __init__(self):
        self.left = None
        self.right = None
        self.data = None

def solve(f):
    output = ''
    line = readIntLine(f, True) # w/ space
    #line = readIntLine(f, False) # w/o space
    #line = readFloatLine(f) # w/ space
    #line = readCharLine(f, True) # w/ space
    #line = readCharLine(f, False) # w/o space

    #row, col = line[0], line[1]
    #arr = readIntArr(f, row, col, True) # w space
    #arr = readIntArr(f, row, col, False) # w/o space
    #arr = readFloatArr(f, row, col) # w/ space
    #arr = readCharArr(f, row, col, True) # w/ space
    #arr = readCharArr(f, row, col, False) # w/o spae                
    x = line[0]
    y = line[1]
    curX = 0
    curY = 0
    jumpsize = 1
    if x > 0:
        curDir = 'E'
        while (x - curX >= jumpsize):
            output += 'E'
            curX += jumpsize
            jumpsize += 1
        while (x != curX):
            if (curDir == 'E'):
                curDir = 'W'
                curX -= jumpsize
                jumpsize += 1
                output += 'W'
            else:
                curDir = 'E'
                curX += jumpsize
                jumpsize += 1
                output += 'E'
    else:
        curDir = 'W'
        while (abs(x - curX) >= jumpsize):
            output += 'W'
            curX -= jumpsize
            jumpsize += 1
        while (x != curX):
            if (curDir == 'E'):
                curDir = 'W'
                curX -= jumpsize
                jumpsize += 1
                output += 'W'
            else:
                curDir = 'E'
                curX += jumpsize
                jumpsize += 1   
                output += 'E'
     
    if y > 0:
        curDir = 'N'
        while (y - curY >= jumpsize):
            output += 'N'
            curY += jumpsize
            jumpsize += 1
        while (y != curY):
            if (curDir == 'N'):
                curDir = 'S'
                curY -= jumpsize
                jumpsize += 1
                output += 'S'
            else:
                curDir = 'N'
                curY += jumpsize
                jumpsize += 1
                output += 'N'
    else:
        curDir = 'S'
        while (abs(y - curY) >= jumpsize):
            output += 'S'
            curY -= jumpsize
            jumpsize += 1
        while (y != curY):
            if (curDir == 'N'):
                curDir = 'S'
                curY -= jumpsize
                jumpsize += 1
                output += 'S'
            else:
                curDir = 'N'
                curY += jumpsize
                jumpsize += 1   
                output += 'N'  
    return output 

###############################################

fin = open(sys.argv[1] + '.in', 'r')
fout = open(sys.argv[1] + '.out', 'w')
T = int(readline(fin))
for t in range(T):
    answer = solve(fin)
    fout.write('Case #%d: %s\n' % (t + 1, answer))
fin.close()
fout.close()
