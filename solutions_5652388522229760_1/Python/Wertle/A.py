import sys

# Open file for processing
filename = sys.argv[1]
inputFile = open(filename, 'r')
lines = [l.rstrip('\n') for l in inputFile]
linesIter = iter(lines)
nCases = int(linesIter.next())


# Process each case
for iCase in range(1,nCases+1):

    # Solve problem
    N = int(linesIter.next())

    if(N == 0):
        print("Case #{}: {}".format(iCase, "INSOMNIA"))
        continue
       

    seenNums = set()
    currNum = 0
    while(True):
        
        currNum += N
        digits = set(str(currNum))
        seenNums.update(digits)

        if len(seenNums) == 10:
            print("Case #{}: {}".format(iCase, currNum)) 
            break
        


