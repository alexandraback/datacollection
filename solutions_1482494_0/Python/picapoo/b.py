
import sys
import copy
from Queue import Queue


class Node:
    def __init__(self, parent, stars, numtry, leftstages):
        self._parent = parent
        self._stars = stars
        self._leftstages = leftstages
        self._numTry = numtry
    
    def parent(self):
        return self._parent
    
    def stars(self):
        return self._stars
    
    def leftStages(self):
        return self._leftstages
    
    def numTry(self):
        return self._numTry
    

def nextNodes(node):
    availableStages = []
    nexts = []
    for stage in node.leftStages():
        if -stage[0] < node.stars():
            break;
        availableStages.append(stage)
        
    twoStarStages = filter(lambda s: s[1] == -2, availableStages)
    tryTwoStage = False 
    if len(twoStarStages) != 0:
        availableStages = twoStarStages
        tryTwoStage = True
        
    
    for stage in availableStages:
        left = copy.deepcopy(node.leftStages())
        left.remove(stage)
        
        removeStage = None;
        for each in left:
            if each[2] == stage[2]:
                removeStage = each
                break;
        
        numstargain = stage[1]
        if removeStage != None:            
            left.remove(removeStage)
            if tryTwoStage:
                numstargain += removeStage[1]
            else:
                left.append((removeStage[0], -1, removeStage[2]))
            left.sort()
            
        child = Node(node, node.stars() + numstargain, node.numTry() + 1, left)
        nexts.append(child)
        
    return nexts
            
        
    
#main
f = open(sys.argv[1], "r")
lines = f.readlines()
f.close()

inputs = Queue()

for each in lines :
    inputs.put(each.replace("\n", "").replace("\r", ""))

ncase = int(inputs.get())

for i in range(0, ncase):
    print "Case #" + str(i+1) + ":",
    nlevels = int(inputs.get())
    
    leftsubmissions = []
    for n in range(0, nlevels):
        onetwo = inputs.get().split(" ")
        leftsubmissions.append((int(onetwo[0]), -1, n))
        leftsubmissions.append((int(onetwo[1]), -2, n))
    
    leftsubmissions.sort();
    
    cands = Queue()
    
    cands.put(Node(None, 0, 0, leftsubmissions))
    
    result = None;
    while not cands.empty():
        top = cands.get()
        if len(top.leftStages()) == 0:
            result = top
            break
        
        nexts = nextNodes(top)
        for nextNode in nexts:
            cands.put(nextNode)
            
    if result == None:
        print "Too Bad"
    else:
        print str(result.numTry()) 
    