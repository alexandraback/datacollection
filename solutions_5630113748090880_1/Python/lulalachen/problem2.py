t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    N = int(raw_input())
    lines = []
    for x in xrange(1,2 * N):
        lines.append([int(s) for s in raw_input().split(" ")])
    soldierList = []
    for line in lines:
        for soldier in line:
            if soldier in soldierList:
                soldierList.remove(soldier)
            else:
                soldierList.append(soldier)
    soldierList.sort()
    print "Case #{}: {}".format(i, ' '.join(map(str, soldierList)))


