from __future__ import print_function
import sys

# print to stderr for debugging
enableDebug = True
def printe(*stuff):
    if enableDebug:
        print(*stuff, file=sys.stderr) 


# Open file for processing
filename = sys.argv[1]
inputFile = open(filename, 'r')
lines = [l.rstrip('\n') for l in inputFile]
linesIter = iter(lines)
nCases = int(linesIter.next())


backSolvedAt = -77
nFlips = -77
stack = []

def flip(ind):

    global nFlips, stack
    nFlips += 1

    frontPart = stack[:ind+1]
    backPart = stack[ind+1:]
    frontPart.reverse()
    for i in range(len(frontPart)): frontPart[i] = not frontPart[i]
    stack = frontPart + backPart


def updateBackSolved():
    global backSolvedAt
    while backSolvedAt > 0 and stack[backSolvedAt-1]:
        backSolvedAt -= 1


# Process each case
for iCase in range(1,nCases+1):
    printe("\nProcessing case " + str(iCase))

    # Solve problem
    stack = [x == '+' for x in next(linesIter)]
    backSolvedAt = len(stack)
    nFlips = 0

    updateBackSolved() 
    while backSolvedAt > 0:

        
        # Find how long the run at the front is
        frontRun = 0
        for i in range(len(stack)):
            if stack[i] == stack[0]:
                frontRun += 1
            else:
                break
    

        # If the run at the front is 1's, invert them (and short circuit if doing so solved the problem)
        if stack[0]:
            flip(frontRun-1)   
            updateBackSolved()
        if backSolvedAt == 0:
            break
        
        
        # Find how long the run at the front is
        frontRun = 0
        for i in range(len(stack)):
            if stack[i] == stack[0]:
                frontRun += 1
            else:
                break


        # Use the front run to solve some of the back
        flip(backSolvedAt-1)


        updateBackSolved()





    print("Case #{}: {}".format(iCase, nFlips))
