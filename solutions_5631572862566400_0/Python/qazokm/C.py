inputFile = open("C.in")
outputFile = open("C.out", "w")

T = int(inputFile.readline())

def inverseBFS(N, start, inverseFriends, seen):
    depth = 0
    seen[start] = True
    frontier = [start]
    while frontier:
        newFrontier = []
        for child in frontier:
            for friend in inverseFriends[child]:
                if not seen[friend]:
                    newFrontier.append(friend)
        depth += 1
        frontier = newFrontier
    
    return depth

def largestLoop(N, F):
    largest = 0
    inverseFriends = [[] for i in range(N)]
    for i in range(N):
        F[i] = F[i] - 1
        inverseFriends[F[i]].append(i)
    for i in range(N):
        loopSize = 0
        seen = [False] * N
        child = i
        while True:
            nextChild = F[child]
            if seen[child] and child == i:
                break
            elif seen[child] and child != i:
                loopSize = 0
                break
            else:
                seen[child] = True
                loopSize += 1
                if F[nextChild] == child:
                    loopSize += inverseBFS(N, nextChild, inverseFriends, seen)
                    break
                else:
                    child = nextChild


        largest = max(loopSize, largest)
    
    return largest
        

for i in range(T):
    N = int(inputFile.readline())
    F = list(map(int, inputFile.readline().split(" ")))

    loop = largestLoop(N, F)

    outputFile.write("Case #" + str(i + 1) + ": " + str(loop) + "\n")

inputFile.close()
outputFile.close()
