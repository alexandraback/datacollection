# read file
f = open("B-small-attempt1.in", "r")
g = open("B-small-ans1.txt", "w")

N = int(f.readline())  # number of cases
k = 0
while k < N:
    LVLS = int(f.readline()) # no of levels
    s1needed, s2needed = {}, {}
    for i in range(LVLS):
        temp = f.readline()
        templst = temp.split()
        templst = [int(e) for e in templst]
        s1needed[i+1], s2needed[i+1] = templst[0], templst[1]

    # last-completed star amt for each level
    # levels for which 2 stars have not been obtained
    last_completed, not_completed = {}, {}
    for i in range(1,LVLS+1):
        last_completed[i] = 0
        not_completed[i]= None

    stars = 0
    cnt = 0
    possible = True
    while(len(not_completed) > 0):
        while (len(s2needed)== 0 or stars >= min(s2needed.values())):
            if len(s2needed) == 0:
                break
            todelete1, todelete2 = [], []
            for e in s2needed:
                if stars >= s2needed[e]: # if we can do star 2
                    # do it!
                    stars = stars + 2 - last_completed[e]
                    cnt += 1
                    last_completed[e] = 2
                    del not_completed[e]
                    todelete2.append(e)
                    if e in s1needed:
                        todelete1.append(e)
            for e in todelete1:
                del s1needed[e]
            for e in todelete2:
                del s2needed[e]

        if len(s2needed) == 0:
            break

        if len(s1needed) == 0 or stars < min(s1needed.values()):
            possible = False
            break

        todel = []
        for e in s1needed:
            if stars >= s1needed[e]: # if we can do, do one
                stars += 1
                cnt += 1
                last_completed[e] = 1
                todel.append(e)
                break
        for e in todel:
            del s1needed[e]

    if possible == True:
        print "Case #: " + str(cnt)
        g.write("Case #" + str(k+1) + ": " + str(cnt) + "\n")
    else:
        print "Case #: Too bad"
        g.write("Case #" + str(k+1) + ": Too Bad" + "\n")

    
    k += 1
