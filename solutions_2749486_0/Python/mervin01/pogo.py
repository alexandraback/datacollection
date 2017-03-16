'''
Created on 12/05/2013

@author: George
'''

testfiles = "B-small-attempt0"
imput = open("%s.in" %testfiles).read()
f = open("%s.txt" %testfiles, "a")
p = open("pogoMap.txt").read().split("\n")
dResults = {}
dJumps = {}
for line in p:
    try:
        x, y, path = line.split(" ")
        dResults[(int(x),int(y))] = path[2:-2]
    except:
        print line





print "init done"




lines = imput.split("\n")
countTests = int(lines[0])
iTested = 0
testStartLine = 1



while iTested < countTests:
    #iterate through the tests in input file
    endX, endY = lines[testStartLine].split(" ")
    X = int(endX)
    Y = int(endY)
    if (X,Y) not in dResults:

        x = 0
        y = 0
        path = ""
        for jump in range(1, 501):
            if x == X - 1:
                x -= jump
                path += "W"
            elif x == X - jump:
                x += jump
                path += "E"
            elif x < X -1:
                x += jump
                path += "E"
            elif x == X + 1:
                x += jump
                path += "E"
            elif x > X:
                x -= jump
                path += "W"

            if y == Y - 1:
                y -= jump
                path += "S"
            elif y == Y - jump:
                y += jump
                path += "N"
            elif y == Y + jump:
                y -= jump
                path += "s"
            elif y < Y -1:
                y += jump
                path += "N"
            elif y == Y + 1:
                y += jump
                path += "N"
            elif y > Y:
                y -= jump
                path += "S"      
            if x == X and y == Y:
                print >>f,    "Case #%s:" %(iTested+1), path
                break   
    else:
        print >>f, "Case #%s:" %(iTested+1), dResults[(int(endX), int(endY))]

    
    iTested += 1
    testStartLine += 1




print "DONE!"
