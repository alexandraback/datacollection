import copy

def show(keys, chests):
    #print(keys, [c.no for c in chests])
    return
class Chest:
    def __init__(self):
        self.no = 0
        self.type = 0
        self.keys = []


typeMax = 201

def possible(keys, chests):
    #print('calling')
    show(keys, chests)

    # graph[i][j] = k represets key of type i cannot open chest of type j indirectly via opening chest of type k in the last step
    direct = [{} for i in range(typeMax)]
    
    for c in chests:
        for k in c.keys:
            direct[c.type][k] = c

    for i in range(1, typeMax):
        if i not in keys:
            continue
        #print('dealing with type: ', i)
        reachableTypes = [0] * typeMax
        for j in direct[i]:
            reachableTypes[j] = i
        activeTypes = list(direct[i])
        while activeTypes:
            #print('active: ', activeTypes, '  reachable: ', reachableTypes[1:])
            t = activeTypes.pop()
            for k in direct[t]:
                if reachableTypes[k] == 0:
                    reachableTypes[k] = t
                    activeTypes.append(k)
            if reachableTypes[i] > 0:
                #print('path found')
                x = [reachableTypes[i]]
                while reachableTypes[x[-1]] != i:
                    x.append(reachableTypes[x[-1]])
                x.reverse()
                #print(x)
                k = i
                y = []
                for q in x:
                    y.append(direct[k][q])
                    k = q
                #y.append(direct[q][i])
                #modify
                #print([q.no for q in y])
                #print('chain')
                for c in y:
                    keys.remove(c.type)
                    keys += c.keys
                    chests.remove(c)
                    show(keys, chests)
                #print('chain end')
                return possible(keys, chests)
    while chests:
        for c in chests:
            if c.type in keys:
                keys.remove(c.type)
                keys += c.keys
                chests.remove(c)
                break
        else:
            return False
    return not chests


def findSolution(keys, chests):
    while chests:
        for i in chests:
            if i.type in keys:
                _k = copy.deepcopy(keys)
                _c = copy.copy(chests)
                _k.remove(i.type)
                _k += i.keys
                _c.remove(i)
                if possible(_k, _c):
                    _k = copy.deepcopy(keys)
                    _c = copy.copy(chests)
                    _k.remove(i.type)
                    _k += i.keys
                    _c.remove(i)
                    return [i.no] + findSolution(_k, _c)
    return []

fin = open('D-small-attempt2.in', 'r')
fout = open('testcase.out', 'w')

T = int(fin.readline().rstrip())
#print(T)

for i in range(T):
    print(i)
    K, N = (int(x) for x in fin.readline().rstrip().split())
    #print(K, N)
    keys = [int(x) for x in fin.readline().rstrip().split()]
    #print('has keys ', keys)
    chests = []
    for j in range(N):
        aChest = Chest()
        aChest.no = j + 1
        aChest.type, k, *aChest.keys = [int(x) for x in fin.readline().rstrip().split()]
        chests.append(aChest)
        #print('chest', j + 1, ': type ', chests[j].type, 'has keys ', chests[j].keys)

    fout.write('Case #' + str(i + 1) + ': ')
    k, c = copy.deepcopy(keys), copy.deepcopy(chests)
    if possible(k, c):
        sol = findSolution(keys, chests)
        fout.write(' '.join([str(x) for x in sol]) + '\n')
    else:
        fout.write('IMPOSSIBLE \n')
    #print('-----')

fin.close()
fout.close()

