t = int(input())

for i in range(t):
    farmCost, farmProduction, winCond = map(float, input().split())

    production = 2.0
    nCookies = 0

    bestTime = 10**8

    time = 0.0

    while True:
        timeToFarm = farmCost / production
        timeToWin = winCond / production

        if timeToWin + time < bestTime:
            bestTime = timeToWin + time

        if timeToFarm + time > bestTime:
            break
        else:
            time += timeToFarm
            production += farmProduction

    print ("Case #{}: {}".format(i + 1, bestTime))


