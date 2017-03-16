#Best friends
visited = []
def GetMaxCircle(l, index):
    global visited

    count = 0
    firstIndex = index
    lastVisited = -1
    while True:
        count += 1
        visited.append(index)
        lastVisited = index
        index = l[index]

        if l[index] == lastVisited:
            newList = l
            for i in visited:
                if i in newList:
                    newList[i] = -1
            maxCircle = 0
            maxVisited = visited
            for i in range(0, len(newList)):
                if newList[i] != -1:
                    tempVisited = visited
                    cur = GetMaxLastVisited(newList, i)
                    if cur > maxCircle:
                        maxCircle = cur
                        maxVisited = visited
                    visited = tempVisited
            if maxCircle > 0 or count < 3:
                return count + maxCircle + 1
            else:
                return -1          
        elif index == firstIndex:
            return count
        elif index in visited:
            return -1
        
    return count

def GetMaxLastVisited(l, index):
    global visited
    if index == -1:
        return 0
    count = 0
    firstIndex = index
    lastVisited = -1
    while True:
        count += 1
        visited.append(index)
        lastVisited = index
        index = l[index]

        if l[index] == lastVisited:
            newList = l
            for i in visited:
                if i in newList:
                    newList[i] = -1
            maxCircle = 0
            maxVisited = visited
            cur = 0
            for i in range(0, len(newList)):
                if newList[i] != -1:
                    tempVisited = visited
                    cur = GetMaxLastVisited(newList, i)
                    if cur > maxCircle:
                        maxCircle = cur
                        maxVisited = visited
                    visited = tempVisited
            visited = maxVisited
            return count + maxCircle + 1
        elif index == firstIndex:
            return -1
        elif index in visited:
            return -1
        
    return count

def main():
    global visited
    f = open("friends.in", "r")
    numCases = int(f.readline())

    for i in range(1, numCases + 1):
        visited = []
        maxCircle = 0
        numStudents = int(f.readline())
        IDs = f.readline().strip().split(' ')
        for k in range(0, numStudents):
            IDs[k] = int(IDs[k]) -1
 
        for j in range(0, numStudents):
            visited = []
            cur = GetMaxCircle(IDs, j)
            if cur > maxCircle:
                maxCircle = cur

        print("Case #", i, ": ", maxCircle, sep='')

main()
