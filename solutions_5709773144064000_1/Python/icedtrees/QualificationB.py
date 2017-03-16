import sys
from decimal import Decimal, getcontext

getcontext().prec = 5
Decimal = float
cases = int(sys.stdin.readline())

for case in range(1, cases + 1):
    sys.stderr.write(str(case))
    farmCost, farmIncome, goal = map(Decimal, sys.stdin.readline().split())

    elapsedTime = Decimal(0)
    currentIncome = Decimal(2.0)
    previousProjected = None
    while True:
        projectedTime = goal / currentIncome + elapsedTime
        if previousProjected and previousProjected < projectedTime:
            break
        previousProjected = projectedTime
        elapsedTime += farmCost / currentIncome
        currentIncome += farmIncome

    result = previousProjected

    print("Case #{}: {}".format(case, result))


