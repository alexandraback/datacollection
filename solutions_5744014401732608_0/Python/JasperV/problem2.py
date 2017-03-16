import math
inp = open("B-small-attempt2.in", "r")
res = open("out1.txt", "w")
cases = int(inp.readline())

def maxPaths(b):
    tot = 1
    for i in range(1, b-1):
        tot += tot
    return tot

for case in range(cases):
    buildings, paths = map(int, inp.readline().split())
    maxP = maxPaths(buildings)
    if maxP < paths:
        res.write("Case #" + str(case+1) + ": " + "IMPOSSIBLE" + "\n")
        print(case)
    else:
        foundP = 0
        solution = [[0 for x in range(buildings)] for y in range(buildings)] 
        solution[0][buildings - 1] = 1
        foundP += 1
        for i in range(1, buildings-1):
            if foundP + math.pow(2, i-1) <= paths:
                solution[0][i] = 1
                solution[i][buildings - 1] = 1
                for c in range(1,i):
                    solution[i][c] = 1
                foundP += math.pow(2, i-1)
            else:
                if foundP < paths:
                    solution[0][i] = 1
                    missing = paths - foundP
                    for c in range(i-1, 0, -1):
                        bonus = math.pow(2, c-1)
                        if bonus <= missing:
                            solution[i][c] = 1
                            foundP += bonus
                            missing -= bonus
                        if foundP == paths:
                            break
                if foundP < paths:
                    solution[i][buildings-1] = 1
            if foundP == paths:
                break
        res.write("Case #" + str(case+1) + ": " + "POSSIBLE" + "\n")
        print(case)
        for i in range(buildings):
            res.write("".join(map(str, solution[i])) + "\n")