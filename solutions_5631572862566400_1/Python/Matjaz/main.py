

T = int(raw_input())


def mark(x):
    while seen[x] != -1 :
        seen[x] = -1
        x = bff[x]


def findDepth(x,p):
    res = 1
    maxDepth = 0
    for child in bffReverse[x]:
        if child == p:
            continue
        depth = findDepth(child,x)
        if depth > maxDepth:
            maxDepth = depth

    return res + maxDepth


def bestConfiguration(x,y):
    return  findDepth(x,y) + findDepth(y,x)



for t in range(1,T+1):
    N = int(raw_input())
    rawFriends = raw_input().split(" ")
    bff = [int(rawFriends[i]) -1 for i in range(N)]
    bffReverse = [[] for i in range(N)]
    for i in range(N):
        bffReverse[bff[i]].append(i)

    seen = [0 for i in range(N)]

    maxCycle = 0
    twoCyclesTotal = 0

    for i in range(N):
        if seen[i] != 0:
            continue

        current = i
        count = 0

        while seen[current] == 0:
            count += 1
            seen[current] = count
            current = bff[current]

        if seen[current] == -1 :
            mark(i)
            continue

        if count - seen[current] + 1 > maxCycle :
            maxCycle = count - seen[current] + 1

        if count - seen[current] + 1 == 2:
            twoCyclesTotal += bestConfiguration(current,bff[current])

        mark(i)


    if twoCyclesTotal > maxCycle :
        answer = twoCyclesTotal
    else :
        answer = maxCycle

    print "Case #"+str(t)+": "+str(answer)






