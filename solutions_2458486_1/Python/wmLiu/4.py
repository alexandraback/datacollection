import copy

class Chest:
    def __init__(self):
        self.no = 0
        self.type = 0
        self.availableKeys = []

typeMax = 201

def openChest(availableKeys, chests, aChest):
    availableKeys.remove(aChest.type)
    availableKeys += aChest.keys
    chests.remove(aChest)    

def possible(availableKeys, chests):
    
    typeDAG = [{} for i in range(typeMax)]
    for c in chests:
        for k in c.keys:
            typeDAG[c.type][k] = c

    for i in range(1, typeMax):
        if i not in availableKeys:
            continue

        reachableTypes = [i if j in typeDAG[i] else 0
                          for j in range(typeMax)]
        activeTypes = list(typeDAG[i])

        #BFS... DFS would be faster
        while activeTypes:
            currentType = activeTypes.pop()
            for k in typeDAG[currentType]:
                if reachableTypes[k] == 0:
                    reachableTypes[k] = currentType
                    activeTypes.append(k)
            
            # cycle found
            if reachableTypes[i] > 0:
                typeChain = [reachableTypes[i]]
                while reachableTypes[typeChain[-1]] != i:
                    typeChain.append(reachableTypes[typeChain[-1]])
                typeChain.reverse()
                
                lastChest = i
                chestChain = []
                for currentChest in typeChain:
                    chestChain.append(typeDAG[lastChest][currentChest])
                    lastChest = currentChest

                #applying the chain
                for aChest in chestChain:
                    openChest(availableKeys, chests, aChest)
                
                return possible(availableKeys, chests)
            
    # no cycle, blindly use all keys
    while chests:
        for aChest in chests:
            if aChest.type in availableKeys:
                openChest(availableKeys, chests, aChest)
                break
        else:
            # stuck
            return False

    return True

def findSolution(keys, chests):
    while chests:
        for aChest in chests:
            if aChest.type in keys:
                backKeys, backChests = copy.deepcopy(keys), copy.copy(chests)
                openChest(backKeys, backChests, aChest)
                if possible(backKeys, backChests):
                    openChest(keys, chests, aChest)
                    return [aChest.no] + findSolution(keys, chests)
    return []

fin = open('D-large.in', 'r')
fout = open('D-large.out', 'w')

T = int(fin.readline().rstrip())

for i in range(T):
    K, N = (int(x) for x in fin.readline().rstrip().split())
    keys = [int(x) for x in fin.readline().rstrip().split()]
    chests = []
    for j in range(N):
        aChest = Chest()
        aChest.no = j + 1
        aChest.type, k, *aChest.keys = [int(x) for x in fin.readline().rstrip().split()]
        chests.append(aChest)

    fout.write('Case #' + str(i + 1) + ': ')

    backKeys, backChests = copy.deepcopy(keys), copy.copy(chests)
    if possible(backKeys, backChests):
        solution = findSolution(keys, chests)
        fout.write(' '.join([str(x) for x in solution]) + '\n')
    else:
        fout.write('IMPOSSIBLE \n')

fin.close()
fout.close()

