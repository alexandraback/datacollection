# codejam 2013 round 1c

# B - pogo

pool = [(0,0,"")]
visited = {}
def solve(tx, ty):
    global pool
    # brute force for small problem
    if (tx,ty) in visited:
        return visited[(tx,ty)]
    while pool:
        x,y,steps = pool.pop(0)
        stepSize = len(steps)+1

        if (x,y) in visited:
            continue
        visited[(x,y)] = steps        
        if x==tx and y==ty:
            return steps

        for step in "NSEW":
            if step=="N":
                pool.append((x,y+stepSize,steps+"N"))
            elif step=="S":
                pool.append((x,y-stepSize,steps+"S"))
            elif step=="E":
                pool.append((x+stepSize,y,steps+"E"))
            elif step=="W":
                pool.append((x-stepSize,y,steps+"W"))
    


import sys
t = int(raw_input().strip())
for caseNum in range(1,t+1):
    sys.stderr.write(str(caseNum)+"\n")
    x,y = [int(s) for s in raw_input().split()]
    print "Case #" + str(caseNum) + ":", solve(x,y)

    
    

