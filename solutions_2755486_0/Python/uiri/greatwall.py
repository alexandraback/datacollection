import sys, copy

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for i in xrange(cases):
    day = 0
    c = 0
    t = int(stdin.pop(0))
    wall = []
    walltobe = []
    offset = 0
    tribes = []
    for j in xrange(t):
        tribe = stdin.pop(0).split(' ')
        for k in xrange(len(tribe)):
            tribe[k] = int(tribe[k])
        tribes.append(tribe)
    while len(tribes):
        toremove = []
        walltobe = copy.copy(wall)
        for tribe in tribes:
            if tribe[0] == day:
                if tribe[2] < offset:
                    east = len(wall)/2 + offset
                    east += tribe[2]
                    while len(wall)/2 < east:
                        wall.insert(0, 0)
                    while len(walltobe)/2 < east:
                        walltobe.insert(0, 0)
                    offset = tribe[2]
                while tribe[3] >= len(wall)/2 + offset:
                    wall.append(0)
                while tribe[3] >= len(walltobe)/2 + offset:
                    walltobe.append(0)
                success = False
                for j in xrange(tribe[2], tribe[3]+1):
                    if wall[2*(j-offset)] < tribe[4]:
                        success = True
                        if walltobe[2*(j-offset)] < tribe[4]:
                            walltobe[2*(j-offset)] = tribe[4]
                    if j < tribe[3] and wall[2*(j-offset)+1] < tribe[4]:
                        success = True
                        if walltobe[2*(j-offset)+1] < tribe[4]:
                            walltobe[2*(j-offset)+1] = tribe[4]
                if success:
                    c += 1
                tribe[0] += tribe[5]
                tribe[1] -= 1
                tribe[2] += tribe[6]
                tribe[3] += tribe[6]
                tribe[4] += tribe[7]
        wall = walltobe
        for j in xrange(len(tribes)):
            if tribes[j][1] == 0:
                toremove.append(j)
        toremove = reversed(toremove)
        for j in toremove:
            tribes.pop(j)
        day += 1
    print "Case #"+str(i+1)+": "+str(c)
