import itertools

inputFile = open('C-small-attempt0.in', 'r')
outputFile = open('C-small-attempt0.out', 'w')

numTests = int(inputFile.readline())

def checkPossible(perm, connectivity, debug = False):
    # Check if it's a valid city ordering
    isPossible = True
    visited = [perm[0]]
    for i in range(1, len(perm)):
        if debug:
            print i, visited
        if connectivity[visited[-1]][perm[i]] == 1:
            visited += [perm[i]]
        else:
            while len(visited) > 0 and connectivity[visited[-1]][perm[i]] == 0:
                visited = visited[:-1]
            if len(visited) == 0:
                isPossible = False
                break
            else:
                visited += [perm[i]]
    return isPossible

for z in range(numTests):
    s = map(lambda x: int(x), inputFile.readline().split())
    n = s[0]
    m = s[1]
    zips = []
    for j in range(n):
        zips += [inputFile.readline().strip()]
    connectivity = [[0]*n for j in range(n)]
    for j in range(m):
        s = map(lambda x: int(x)-1, inputFile.readline().split())
        connectivity[s[0]][s[1]] = 1
        connectivity[s[1]][s[0]] = 1

    minIndex = zips.index(min(zips))
    perms = list(itertools.permutations(range(n)))
    minStr = '99999'*n

    for perm in perms:
        if perm[0] != minIndex:
            continue
        # Check if it's better than our minStr, i.e. worth considering
        thisStr = ''
        for i in perm:
            thisStr += zips[i]
        if thisStr >= minStr:
            continue

        
        
        if checkPossible(perm, connectivity):
            minStr = thisStr

    outputFile.write("Case #" + str(z+1) + ': ' + minStr + '\n')
    
            
    




inputFile.close()
outputFile.close()
