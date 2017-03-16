import string

file_name = 'B-small-attempt0.in'

cookieInput = open(file_name, 'r')
data = string.split(cookieInput.read().strip(), '\n')
numCases = int(data[0])

for i in range(1, numCases+1):
    C,F,X = [float(x) for x in string.split(data[i],' ')]
    maxCost = X/2
    addedCost = 0
    rate = 2.0
    numFarms = 0
    while True:
        if addedCost + C/rate + X/(rate+F) < maxCost:
            maxCost = addedCost + C/rate + X/(rate+F)
            addedCost += C/rate
            rate += F
            numFarms +=1
        else:
            break
    print "Case #" + str(i) + ":", maxCost
