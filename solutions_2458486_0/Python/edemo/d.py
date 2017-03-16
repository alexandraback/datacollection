#!/usr/bin/python3.2
import copy

filename = 'D-small-attempt1.in'
#filename = 'd-test.in'

FILE = open(filename)
T = int(FILE.readline())

def solve(keys,chests, opened,order):
    for i,chest in enumerate(chests):
        if chest['req'] in keys:
            newKeys = copy.copy(keys)
            newKeys.remove(chest['req'])
            newKeys += chest['con']
            opened += chests[i]
            newChests = chests[:i] + chests[i+1:]
            newOrder = copy.copy(order)
            newOrder.append(chest['ix'])

            if len(newChests) == 0: return str(newOrder)
            if solvable(newKeys,newChests):
                temp = solve(newKeys,newChests, opened,newOrder)
                if (temp != 'IMPOSSIBLE'): return temp

    return 'IMPOSSIBLE'

def solvable(keys,chests):
    if (len(keys) == 0):
        return False

    flag = 0
    for chest in chests:
        if chest['req'] in keys:
            flag = 1
            break
    if flag == 0:
        return False

    for chest in chests:
        chest['flag'] = 0

    newKeys = set(keys)
    flag = 1
    while flag:
        flag = 0
        for chest in chests:
            if (chest['req'] in newKeys) and (chest['flag'] == 0):
                flag = 1
                chest['flag'] = 1
                newKeys = newKeys.union(set(chest['con']))

    for chest in chests:
        if chest['flag'] == 0:
            return False

    num = len(keys)
    for chest in chests:
        num += len(chest['con'])
    num -= len(chests)
    if num < 0: return False

    num = {k:0 for k in newKeys}
    for key in keys:
        num[key] += 1

    for chest in chests:
        num[chest['req']] -= 1
        for k in chest['con']:
            num[k] += 1

    for ix in num:
        if num[ix] < 0: return False

    return True

for t in range(1,T+1):
    k,n = [int(x) for x in FILE.readline().split(' ')]
    keys = [int(x) for x in FILE.readline().split(' ')]

    chests = []
    for i in range(0,n):
        raw = FILE.readline().split(' ')
        chests.append({})
        chests[i]['req'] = int(raw[0])
        chests[i]['con'] = [int(x) for x in raw[2:]]
        chests[i]['ix'] = i+1

    if solvable(keys,chests):
        sol = solve(keys,chests,[],[])
        if sol != 'IMPOSSIBLE':
            sol = str(sol)[1:-1].split(', ')
            sol = ' '.join(sol)
    else:
        sol = 'IMPOSSIBLE'
    print('Case #' + str(t) + ': ' + sol)