# solve the problem
def minGames(levels, levelstars):
    stars = 0
    runs = 0
    counter = [0] * levels  
    level1req, level2req = zip(*levelstars)
    level1req = list(level1req)
    level2req = list(level2req)
    ohnoes = 0
    while stars < 2*levels:
        i = 0
        increase = 0
        while i < levels:
            if level2req[i] <= stars and counter[i] == 0:
                counter[i] += 2
                stars += 2
                runs += 1
                increase = 1
            i += 1
        if increase == 0:
            i = 0
            while i < levels:
                if level2req[i] <= stars:
                    if counter[i] == 1:
                        counter[i] += 2
                        stars += 1
                        runs += 1
                        increase = 1
                        break
                i += 1
            i = 0
            while i < levels:
                if level1req[i] <= stars:
                    if counter[i] == 0:
                        counter[i] += 1
                        stars += 1
                        runs += 1
                        increase = 1
                        break
                i += 1
        if increase == 0:
            return 0
    return runs
                
# grab number of cases
cases = int(raw_input())

# array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    levels = int(raw_input())
    levelstars = []
    for level in range(levels):
        stdin = raw_input()
        A, B = map(int, stdin.split(' '))
        levelstars.append((A,B))
    inputs.append((ncase, levels, levelstars))  

# calculate answer
for case in inputs:
    ncase, levels, levelstars = case
    sol = minGames(levels, levelstars)
    if sol == 0:
        print "Case #" + str(ncase + 1) + ": Too Bad"
    else:
        print "Case #" + str(ncase + 1) + ": "  + str(sol)
