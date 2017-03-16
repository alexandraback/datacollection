import sys
from itertools import permutations
from math import factorial

T = int(sys.stdin.readline().strip())

for testNum in range(T):
    sys.stdin.readline()

    cars = sys.stdin.readline().strip().split()

    ans = None

    cars2 = []

    for c in cars:
        car = ""

        for ch in c:
            if (car == "") or (ch <> car[-1]):
                car += ch

        cars2.append(car)

    cars = cars2

    #print cars

    middles = []
    for i, c in enumerate(cars):
        for ch in c[1:-1]:
            middles.append(ch)

    if len(middles) <> len(set(middles)):
        ans = "0"

    for c in cars:
        if (c[0] in middles) or (c[-1] in middles):
            ans = "0"

    if not ans:
        cars = [(c[0], c[-1]) for c in cars]
        #print cars

        used = set()
        permsList = []
        while True:
            found = False
            for ci, c in enumerate(cars):
                if (c[0] <> c[1]) and (c not in used): # a start piece
                    start = c
                    startI = ci
                    found = True
                    break

            if not found:
                break

            #print start 

            used.add(start)

            endPieces = filter(lambda c: c[0] == start[1], cars)

            hardEnds = filter(lambda c: c[0] <> c[1], endPieces)

            softEnds = filter(lambda c: c[0] == c[1], endPieces)

            #print endPieces, hardEnds, softEnds
            

            if len(hardEnds) > 1:
                ans = "0"
                break

            if len(hardEnds) == 1:
                endChar = hardEnds[0][1]
            else:
                endChar = start[1]

            #print endChar

            permsList.append( factorial(len(softEnds)) )

            cars = [c for ci, c in enumerate(cars) if ((ci <> startI) and (c not in endPieces))]

            #print cars
            cars.append((start[0], endChar))

            #print cars

        if not ans:
            used = set()
            while True:
                found = False
                for ci, c in enumerate(cars):
                    if (c[0] <> c[1]) and (c not in used): # an end piece
                        endP = c
                        endPI = ci
                        found = True
                        break

                if not found:
                    break

                #print start 

                used.add(endP)

                startPieces = filter(lambda c: c[1] == endP[0], cars)
                softStarts = filter(lambda c: c[0] == c[1], startPieces)

                permsList.append( factorial(len(softStarts)) )

                cars = [c for ci, c in enumerate(cars) if ((ci <> endPI) and (c not in startPieces))]

                #print cars
                cars.append((endP[0], endP[1]))

                #print cars

        if not ans:

            used = set()
            while True:
                found = False
                for c in cars:
                    if (c[0] == c[1]) and (c not in used):
                        start = c
                        found = True
                        break

                if not found:
                    break

                used.add(start)

                totalNum = cars.count(start)

                permsList.append( factorial(totalNum) )

                cars = [c for c in cars if (c <> start)]

                cars.append(start)


            #print permsList, cars
            permsList.append( factorial(len(cars)) )

            ans = reduce(lambda a,b: a*b, permsList)


        #for p in permutations(range(len(cars))):
        #
        #    pi = 0
        #    while True:
        #        cars[pi][-1] == 

        ans = ans % 1000000007

    
    print "Case #%d: %s"%(testNum+1, str(ans))