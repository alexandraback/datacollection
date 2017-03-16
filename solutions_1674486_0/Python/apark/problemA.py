f = open("A-small-attempt2.in", 'r')
allfile = f.read()
lines = allfile.split("\n")
output = []

def equals(tup, tup2):
    if len(tup) != len(tup2):
        return False
    for ele in tup:
        if ele not in tup2:
            return False
        tup2.remove(ele)
    return True

def contains(arr, tup):
    for ele in arr:
        if equals(ele, tup):
            return True
    return False

T = int(lines.pop(0))
for Tcount in xrange(T):
    print Tcount
    line = lines.pop(0)
    N = int(line)
    #print N
    paths = []
    for rawr in xrange(N):
        paths.append([])
        for raw in xrange(N):
            paths[rawr].append([])
    for Ncount in xrange(N):
        line = lines.pop(0)
        split = line.split(" ")
        M = int(split[0])
        classes = [int(split[n]) for n in xrange(1, len(split))]
        for rawr in classes:
            paths[Ncount][rawr-1].append([Ncount, rawr-1])
            #print [Ncount, rawr-1]
    pathsAdded = True
    diamondPath = False
    while pathsAdded and not diamondPath:
        pathsAdded = False
        for i in xrange(N):
            if diamondPath:
                break
            for j in xrange(N):
                if diamondPath:
                    break
                for k in xrange(N):
                    if diamondPath:
                        break
                    if len(paths[i][j]) > 0 and len(paths[j][k]) > 0:
                        newPath = paths[i][j][0][:-1] + paths[j][k][0]
                        if not contains(paths[i][k], newPath):
                            if len(paths[i][k]) > 0:
                                diamondPath = True
                            pathsAdded = True
                            paths[i][k].append(newPath)
                            #print i, k, newPath, paths[i][j][0], paths[j][k][0]
                            
    if diamondPath:
        output.append("Yes")
    else:
        output.append("No")
    
    

f = open("problemA.out", 'w')
for x in xrange(len(output)):
    out = "Case #" + str(x+1) + ": " + str(output[x]) + "\n"
    f.write(out)
    print(out)
