
class chest:
    def __init__(self):
        self.keys=[]
        self.priority=0
        self.openWith=0

class relData:
    def __init__(self):
        self.keys=[]
        self.openWith=0

def possible(keys,chests):
    required=[]
    totalKeys=[]
    for each in chests:
        required.append(each.openWith)
        totalKeys.extend(each.keys)
    totalKeys.extend(keys)
    try:
        for key in required:
            totalKeys.remove(key)
        return True
    except:
        return False
    


def copyList(curList):
    newList=[0]*len(curList)
    for index in xrange(0,len(curList)):
        newList[index]=curList[index]
    return newList

def removeChest(curChests,toRemove):
    newList=[]
    for index in xrange(0,len(curChests)):
        if curChests[index]==toRemove:
            break

def seenContains(newChest,seen):
    chestKeys=newChest.keys
    chestKeys.sort()
    chestOpenWith=newChest.openWith
    for each in seen:
        if chestOpenWith==each.openWith:
            nextKeys=each.keys
            nextKeys.sort()
            if nextKeys==chestKeys:
                return True
    return False

def recChests(curKeys,unopenedChests,known):
    if unopenedChests==[]:
        return []
    
    curKeys.sort()
    keyKey=",".join(curKeys)
    unopened=[]
    for each in unopenedChests:
        unopened.append(each.priority)
    chestKey=";".join(unopened)
    finalKey=keyKey+":"+chestKey
    if known.has_key(finalKey):
        return known[finalKey]
    bestAnswer="IMPOSSIBLE"
    seen=[]
    for trialChest in range(0,len(unopenedChests)):
        if seenContains(unopenedChests[trialChest],seen):
            continue
        nextSeen=relData()
        nextSeen.keys=unopenedChests[trialChest].keys
        nextSeen.openWith=unopenedChests[trialChest].openWith
        seen.append(nextSeen)
        
        if unopenedChests[trialChest].openWith in curKeys:
            newKeys=copyList(curKeys)
            newKeys.remove(unopenedChests[trialChest].openWith)
            newKeys.extend(unopenedChests[trialChest].keys)
            newChests=copyList(unopenedChests)
            newChests.remove(unopenedChests[trialChest])
            nextAnswer=recChests(newKeys,newChests,known)
            if not nextAnswer=="IMPOSSIBLE":
                nextAnswer=[unopenedChests[trialChest].priority]+nextAnswer
                bestAnswer=nextAnswer
                break
    known[finalKey]=bestAnswer
    return bestAnswer
            
    

def getAnswer(keys,chests,D):
    
    if not possible(keys,chests):
        print "IMPOSSIBLEHERE"
        return "IMPOSSIBLE"
    answer=recChests(keys,chests,D)
    print answer
    if answer=="IMPOSSIBLE":
        return "IMPOSSIBLE"
    
    return " ".join(answer)


X=open("dsm3.in")
z=open("output.txt","w")
case=0
cases=int(X.readline())

while case<cases:
    case+=1
    known={}
    print case
    currentline=X.readline().rstrip().lstrip().split()
    chests=int(currentline[1])
    keys=X.readline().rstrip().lstrip().split()
    priority=0
    chestList=[]
    while chests>0:
        chests-=1
        priority+=1
        newChest=chest()
        currentline=X.readline().rstrip().lstrip().split()
        newChest.openWith=currentline[0]
        newChest.priority=str(priority)
        newChest.keys=currentline[2:]
        chestList.append(newChest)
        
    z.write("Case #"+str(case)+": "+getAnswer(keys,chestList, known)+"\n")
z.close()
