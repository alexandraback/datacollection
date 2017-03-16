import sys, copy


def solve(x,y):
    
    movements = []
    
    xDist = abs(x)
    yDist = abs(y)
    xMoves = []
    yMoves = []
    
    totalDist = xDist + yDist
    
    i = 0
    while sum(range(1,i)) < totalDist:
        i += 1
    
    moveList = range(1,i)
    
    amountToLose = sum(moveList) - totalDist
    
    if amountToLose % 2 == 1:#odd
        moveList.append(i)
        amountToLose += i
    
    moveListOrig = copy.deepcopy(moveList) #after making odd, but before re-shuffling
    
    #amountToLose is now even
        
    if amountToLose <> 0:
        moveList.remove(amountToLose/2)    
        moveList.insert(0, -amountToLose/2)
    
    #now it adds up
    
    #find how to sum to xDist
    remaining = xDist
    for i in moveList[::-1]:
        if remaining >= i:
            moveList.remove(i)
            xMoves.append(i)
            remaining -= i
            
            if not remaining:
                break
    
    yMoves = moveList # what's left
          

    for m in moveListOrig:        
        
        if m == amountToLose/2: # this is a y move
            if y > 0:
                movements.append("S")
            else:
                movements.append("N")            
        
        elif m in xMoves:
            if x > 0:
                movements.append("E")
            else:
                movements.append("W")
                
        elif m in yMoves:
            if y > 0:
                movements.append("N")
            else:
                movements.append("S")        
    
    return "".join(movements)



fp = open(sys.argv[1], "r")
fpOut = open("output_%s.txt"%sys.argv[1], "w")

lines = fp.readlines()
numCases = int(lines.pop(0).strip())

for c in range(1, numCases+1):
    
    x, y = map(int, lines.pop(0).strip().split(" "))    
    
    result = solve(x,y)
    
    outString = "Case #%d: %s\n"%(c, result)
    print outString,
    fpOut.write(outString)
    
fpOut.close()
