import sys

cases = int(sys.stdin.readline())

for case in range(1, cases + 1):
    farmCost, farmIncome, goal = map(float, sys.stdin.readline().split())

    elapsedTime = 0
    currentIncome = 2.0
    previousProjected = float("inf")
    while True:
        projectedTime = goal / currentIncome + elapsedTime
        if previousProjected < projectedTime:
            break
        previousProjected = projectedTime
        elapsedTime += farmCost / currentIncome
        currentIncome += farmIncome

    result = previousProjected

    print("Case #{}: {}".format(case, result))


