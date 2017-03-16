fin = open("in2.txt", "r")
fout = open("out2.txt", "w")


def solve(coders, jammers):
    places = len(coders)
    nr1 = []
    nr2 = []
    for x in xrange(places):
        nr1.append(0)
        nr2.append(0)

    pos1 = []
    pos2 = []
    best = 9999
    bestVals = [9999,0]
    over1 = False
    for x in xrange(places):
        if coders[x] == '?':
            pos1.append(x)
        else:
            nr1[x] = int(coders[x])
        if jammers[x] == '?':
            pos2.append(x)
        else:
            nr2[x] = int(jammers[x])

    keep2 = nr2
    while True:
        nr2 = keep2
        while True:
            val1 = 0
            val2 = 0
            for x in nr1:
                val1 = val1 * 10
                val1 += x
            for x in nr2:
                val2 = val2 * 10
                val2 += x
            if abs(val1 - val2) == best and val1 < bestVals[0] and val2 < bestVals[1]:
                best = abs(val1 - val2)
                bestVals[0] = val1
                bestVals[1] = val2
            if abs(val1 - val2) < best:
                best = abs(val1 - val2)
                bestVals[0] = val1
                bestVals[1] = val2

            over2 = True
            for y in xrange(places - 1, -1, -1):
                if y in pos2:
                    nr2[y] += 1
                    if nr2[y] < 10:
                        over2 = False
                        break
                    else:
                        nr2[y] = 0
            if over2:
                break
        over1 = True
        for x in xrange(places - 1, -1, -1):
            if x in pos1:
                nr1[x] += 1
                if nr1[x] < 10:
                    over1 = False
                    break
                else:
                    nr1[x] = 0
        if over1:
            break

    bestVals[0] = str(bestVals[0])
    bestVals[1] = str(bestVals[1])
    while len(bestVals[0]) < places:
        bestVals[0] = "0" + bestVals[0]
    while len(bestVals[1]) < places:
        bestVals[1] = "0" + bestVals[1]
    return bestVals



T = int(fin.readline().strip())
for x in xrange(T):
    line = fin.readline().strip()
    (coders, jammers) = line.split(" ")
    (coders, jammers) = solve(coders, jammers)
    fout.write("Case #%d: %s %s\n" % (x+1, coders, jammers))

fin.close()
fout.close()