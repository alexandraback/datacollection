inputFile = open("A-small-attempt0 (2).in", 'r')
outputFile = open("diamondOutSmall.txt", 'w')
numTests = int(inputFile.readline())

def hasDiamond(adjLists):
    for i in range(len(adjLists)):
        for j in range(len(adjLists)):
            if i != j and doubleDFS(i, j, adjLists):
                return True
    return False

def doubleDFS(s, t, adjLists):
    visited = []
    q = [s]
    count = 0
    parent1 = {}
    while q != []:
        n = q.pop()
        if n in visited:
            continue
        if n == t:
            count += 1
        visited += [n]
        for j in range(len(adjLists[n])):
            if adjLists[n][j] not in visited:
                parent1[adjLists[n][j]] = n
                q += [adjLists[n][j]]

                
    visited = []
    q = [s]
    count = 0
    parent2 = {}
    while q != []:
        n = q.pop()
        if n in visited:
            continue
        if n == t:
            count += 1
        visited += [n]
        for j in range(len(adjLists[n])-1, -1, -1):
            if adjLists[n][j] not in visited:
                parent2[adjLists[n][j]] = n
                q += [adjLists[n][j]]

    if t not in parent1 or t not in parent2:
        return False
    a = t
    b = t
    while a == b:
        if a == s:
            return False
        a = parent1[a]
        b = parent2[b]
        if a != b:
            return True
    return False

for i in range(numTests):
    n = int(inputFile.readline())
    adjLists = []
    for j in range(n):
        adjs = inputFile.readline().split()
        x = []
        for k in range(1, len(adjs)):
            x += [int(adjs[k])-1]
        adjLists += [x]
    outputFile.write('Case #' + str(i+1) + ': ')
    if hasDiamond(adjLists):
        outputFile.write('Yes\n')
    else:
        outputFile.write('No\n')
inputFile.close()
outputFile.close()
