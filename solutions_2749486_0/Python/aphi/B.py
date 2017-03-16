import sys


def solve(x,y):
    
    dest = (x,y)
    current = (0,0)
    movements = []
    
    #fine tuning
    xDist = dest[0] - current[0]
    yDist = dest[1] - current[1]
    
    if xDist > 0:
        movements.append("WE"*abs(xDist))
    elif xDist < 0:
        movements.append("EW"*abs(xDist))
    
    if yDist > 0:
        movements.append("SN"*abs(yDist))
    elif yDist < 0:
        movements.append("NS"*abs(yDist))
    
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
