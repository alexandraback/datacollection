from datetime import datetime

#Input
fName = raw_input('Enter Filename of Input:\n')
with open(fName) as f:
    inp = [line.rstrip() for line in f]
#Output
timestamp = datetime.now().strftime("%H.%M.%S")
out = open('b'+timestamp+'.out', 'w')
#Stuff
caseCount = int(inp[0])
for case in range(1,caseCount+1):
    #Problem
    line = inp[case].split()
    fCost = float(line[0])
    fBen = float(line[1])
    goal = float(line[2])
    #Solving
    cook = 0.0
    rate = 2.0
    time = 0.0
    while cook < goal:
        if(cook>=fCost):
            toGo = goal-cook
            noBuyTime = toGo/rate
            buyTime = (toGo+fCost)/(rate+fBen)
            if(noBuyTime<buyTime):
                time += (goal-cook) / rate
                cook=goal
            else:
                cook -= fCost
                rate += fBen
        else:
            incr = min(fCost,goal) - cook
            cook += incr
            time += incr / rate
    pri = 'Case #'+str(case)+': '+str(round(time,7))
    out.write(pri+'\n')
out.close()
