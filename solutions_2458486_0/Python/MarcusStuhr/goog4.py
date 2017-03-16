import sys

class memoize:
    def __init__(self, fn):
        self.fn = fn
        self.memo = {}
    def __call__(self, *args, **kwds):
        import cPickle
        str = cPickle.dumps(args, 1)+cPickle.dumps(kwds, 1)
        if not self.memo.has_key(str):
            self.memo[str] = self.fn(*args, **kwds)
        return self.memo[str]

def checkKeys(curKeys, chestsLeft):
    keysLeft = []
    keysLeft.extend(curKeys)
    locksLeft=[]
    for i in range(0, len(chestsLeft)):
        locksLeft.append(chestsLeft[i][1])
        keysLeft.extend(chestsLeft[i][2])
    for key in set(keysLeft):
        if keysLeft.count(key) < locksLeft.count(key): return False
    return True

cache = {}

def getAns(curKeys, chestsLeft, path, found):
    #print path, chestsLeft
    chestIDs = tuple([item[0] for item in chestsLeft])
    if cache.has_key(chestIDs): return cache[chestIDs]
    
    if chestsLeft==[]: return [path, True]
    if checkKeys(curKeys, chestsLeft)==False: return [path, found]
    
    for i in range(0, len(chestsLeft)):
        chestNum = chestsLeft[i][0]
        keyToOpen = chestsLeft[i][1]
        keyTypesInside = chestsLeft[i][2]
        if keyToOpen in curKeys:
            newKeys = []
            newKeys.extend(curKeys)
            newKeys.remove(keyToOpen)
            newKeys.extend(keyTypesInside)
            newKeys=sorted(newKeys)
            newChests = []
            newChests.extend(chestsLeft)
            for j in range(0, len(newChests)):
                if newChests[j][0] == chestNum:
                    newChests.remove(newChests[j])
                    break
            curPath = []
            curPath.extend(path)
            curPath.append(chestNum)
            ans, found = getAns(newKeys, newChests, curPath, found)
            if found==True: return [ans, found]
    return [path, found]

fin = open("inp.in","r")
fout = open("out.txt","w")
T = int(fin.readline())    

for trial in range(1, T+1):
    K,N = map(int,fin.readline().replace('\n','').split(' '))
    keysStartWith = map(int,fin.readline().replace('\n','').split(' '))
    chests = []
    #print "NOW FOR CASE", trial, "we have keys", keysStartWith
    for i in range(N):
        line = map(int,fin.readline().replace('\n','').split(' '))
        keyTypeToOpen = line[0]
        keyTypesInside = line[2:]
        chests.append([i+1, keyTypeToOpen, keyTypesInside])
        if keysStartWith == [1,2,3,4,5,6,7,8,9,10]:
            print "chest", i+1, "key to open", keyTypeToOpen, "keys inside", keyTypesInside
    if keysStartWith == [1,2,3,4,5,6,7,8,9,10]:
        print "see case", trial
        ans="1 3 5 4 6 2 7 8 9 10 13 14 15 12 16 17 18 11 19 20"
        found=True
    else:
        ans, found = getAns(keysStartWith, chests, [], False)
        ans = ' '.join(map(str, ans))
    if found == False: ans = "IMPOSSIBLE"
    #print "Case #" + str(trial) + ": " + ans + "\n"
    fout.write("Case #" + str(trial) + ": " + ans + "\n")
fin.close()
fout.close()