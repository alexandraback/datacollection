#!/usr/bin/python
import sys

def copyChests(chests):
    newChests = []
    for i in range(len(chests)):
        chestNo = chests[i][0]
        keyUnlock = chests[i][1]
        nkeyinside = chests[i][2]
        keysinside = []
        for key in chests[i][3]:
            keysinside.append(key)
        newChests.append((chestNo,keyUnlock,nkeyinside,keysinside))
    return newChests

def copyKeys(keys):
    newkeys = {}
    for key in keys:
        newkeys.update({key:keys[key]})
    return newkeys

def trapped(chests,keyshave,keysneed):
    keyscanget = {}
    for key in keyshave:
        if key in keyscanget:
            keyscanget[key] = keyscanget[key]+keyshave[key]
        else:
            keyscanget.update({key:keyshave[key]})
    updated = True
    newChests = copyChests(chests)
    while updated and newChests:
        updated = False
        deleted = []
        for i in range(len(newChests)):
            if newChests[i][1] in keyscanget:
                updated = True
                deleted.append(i)
                for key in newChests[i][3]:
                    if key in keyscanget:
                        keyscanget[key] = keyscanget[key]+1
                    else:
                        keyscanget.update({key:1})
        if deleted:
            nextIterChests = []
            for i in range(len(newChests)):
                if i not in deleted:
                    nextIterChests.append(newChests[i])
            newChests = nextIterChests
    for key in keysneed:
        need = keysneed[key]
        canget = keyscanget.get(key,None)
        if not canget or canget < need:
            return True
    return False

def Find_Treasure(chests,keyshave,keysneed, order):
    if len(keyshave) == 0:
        return False
    if len(chests) == 1:
        result = keyshave.get(chests[0][1],None)
        if result:
            order.append(chests[0][0])
            return True
        else:
            return False
    if trapped(chests,keyshave,keysneed):
        return False
    for i in range(len(chests)):
        result = keyshave.get(chests[i][1],None)
        if result:
            #Try using that chest next
            newChests = copyChests(chests)
            newKeysHave = copyKeys(keyshave)
            newKeysNeed = copyKeys(keysneed)
            #Use up key
            newKeysHave[chests[i][1]] = newKeysHave[chests[i][1]] - 1
            newKeysNeed[chests[i][1]] = newKeysNeed[chests[i][1]] - 1
            if newKeysHave[chests[i][1]] == 0:
                del newKeysHave[chests[i][1]]
            if newKeysNeed[chests[i][1]] == 0:
                del newKeysNeed[chests[i][1]]
            #add keys from chest to store
            for key in chests[i][3]:
                if key in newKeysHave:
                    newKeysHave[key] = newKeysHave[key] + 1
                else:
                    newKeysHave.update({key:1})
            #Remove chest
            del newChests[i]
            #Attempt to continue with current state
            result2 = Find_Treasure(newChests,newKeysHave,newKeysNeed,order)
            if result2:
                order.insert(0,chests[i][0])
                return True
    return False
            
if len(sys.argv) != 2:
    print "Usage: ./treasure.py <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)
data = fin.readlines()
ntests = int(data[0].strip())
line = 1
for test in range (1, ntests+1):
    info = data[line].strip().split()
    line+=1
    nkeys = int(info[0])
    nchests = int(info[1])
    info = data[line].strip().split()
    line+=1
    keys = {}
    keyshave = {}
    keysneed = {}
    for key in info:
        if key in keys:
            keys[key] = keys[key]+1
        else:
            keys.update({key:1})
        if key in keyshave:
            keyshave[key] = keyshave[key]+1
        else:
            keyshave.update({key:1})
    chests = []
    for i in range(nchests):
        info = data[line].strip().split()
        line+=1
        unlock = info[0]
        if unlock in keysneed:
            keysneed[unlock] = keysneed[unlock]+1
        else:
            keysneed.update({unlock:1})
        nkeyinside = int(info[1])
        keysinside = []
        for j in range(2, len(info)):
            keysinside.append(info[j])
            if info[j] in keyshave:
                keyshave[info[j]] = keyshave[info[j]]+1
            else:
                keyshave.update({info[j]:1})
        chests.append((i+1,unlock,nkeyinside,keysinside))
    valid = True
    for key in keysneed:
        need = keysneed[key]
        have = keyshave.get(key, None)
        if not have or need > have:
            valid = False
            break
    if valid == False:
        print "Case #%d: IMPOSSIBLE"%test
        continue
    order = []
    
    result = Find_Treasure(chests,keys,keysneed, order)
    if result:
        sys.stdout.write("Case #%d:"%test)
        for chest in order:
            sys.stdout.write(" %d"%chest)
        print ""
    else:
        print "Case #%d: IMPOSSIBLE"%test
    
sys.exit(0)
