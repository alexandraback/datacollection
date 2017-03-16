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


def solve(f):
    output = ''
    #N = readIntLine(f, True) # w/ space
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

    line = readline(f).split()
    s = line[0]
    n = int(line[1])
    bs = ""
    for c in s:
        if c in {'a','e','i','o','u'}:
            bs += '0'
        else:
            bs += '1'
    j = 1
    a = set()
    needle = ""
    for i in range(n):
        needle += "1"
    count = 0
    while True:
        for i in range(len(bs) - j + 1):
            a.add(bs[i:i+j])
            if needle in bs[i:i+j]:
                count += 1
        if j==len(bs):
            break
        j+=1
        #string=string[1:]
    
    return count 

###############################################

fin = open(sys.argv[1] + '.in', 'r')
fout = open(sys.argv[1] + '.out', 'w')
T = int(readline(fin))
for t in range(T):
    answer = solve(fin)
    fout.write('Case #%d: %s\n' % (t + 1, answer))
fin.close()
fout.close()
