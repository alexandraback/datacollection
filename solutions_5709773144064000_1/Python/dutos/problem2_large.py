import os, re

inf = open('problem2_large.txt', 'r')

numproblems = int(inf.readline())

outf = open('out2_large.txt', 'w')

for problemnum in range(numproblems):
    values = inf.readline()
    values = re.sub('\n', '', values)
    values = values.split()

    farmcost = float(values[0])
    farmrate = float(values[1])
    win = float(values[2])

    #dont really need this as the current cookie should always be zero when
    #we make a new decision
    currentcookie = 0.0
    currentrate = 2.0

    totalseconds = 0.0

    while True:
        timeToNextFarm = (farmcost) / currentrate

        timeToNextFarmAndWin = timeToNextFarm + win / (currentrate + farmrate)

        timeToWin = win / currentrate
        
        if timeToWin < timeToNextFarmAndWin:
            totalseconds += timeToWin
            break
        else:
            totalseconds += timeToNextFarm
            currentrate += farmrate

    msg = 'Case #' + str(problemnum + 1) + ': %.7f' % totalseconds
    print msg
    outf.write(msg + '\n')

outf.close()
inf.close()
            

    
