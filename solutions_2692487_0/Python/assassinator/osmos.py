from Queue import Queue
def isGoalState(state):
    isGoal = False
    A = state[0]
    Moles = state[1]
    Moles = list(Moles)
    Moles.sort()
    #print Moles,"Goal"
    if Moles.__len__() == 0:
        return True
    for mole in Moles:
        if A > mole:
            A += mole
            isGoal = True
        else:
            isGoal = False
            break
        
    return isGoal
    
def getSuccessors(state):
    A = state[0]
    Moles = state[1]
    successers = []
    Moles = list(Moles)
    Moles.sort()
    temp = A
    #print A
    if A>1:
        for mole in Moles:
            if mole < temp:
                temp += mole
        successers.append((A,tuple(Moles+[temp-1])))
    if Moles.count(A) == Moles.__len__():
        #print Moles,"succ"
        if Moles.__len__() > 0:
            initialMoles = Moles[:]
            initialMoles.pop()
            successers.append((A,tuple(initialMoles)))
        return successers
    
    count = 0
    temp = A
    for mole in Moles:
            if mole < temp:
                temp+=mole
                count+=1
            else:
                break
                
    
    for i in xrange(count,Moles.__len__()):
        #print Moles[i]
        initialMoles = Moles[:]
        if Moles[i] > temp:
            initialMoles.remove(Moles[i])
            successers.append((A,tuple(initialMoles)))
            
    return successers
    
    

def traverse_path(fromNode):
    def make_path(toNode, graph):
        result = []
        while 'Root' != toNode:
            result.append(toNode)
            toNode = graph[toNode]
        #result.reverse()
        #print result
        return result

    q = Queue()
    q.put(fromNode)
    graph = {fromNode: 'Root'}

    while not q.empty():
        # get the next node and add its neighbours to queue
        #print q.qsize()
        current = q.get()
        for neighbor in getSuccessors(current):
            # use neighbor only continue if not already visited
            #print neighbor
            if neighbor not in graph:
                graph[neighbor] = current
                q.put(neighbor)

        # check if destination
        if isGoalState(current):
            return make_path(current, graph)
    return []

if __name__ == "__main__":
    T = int(raw_input())
    count = 1
    while T>0:
        AN = [int(i) for i in raw_input().strip().split()]
        A = AN[0]
        Moles = [int(i) for i in raw_input().strip().split()]
        startstate = (A,tuple(Moles))
        #print startstate
        print "Case #"+str(count)+": "+str(traverse_path(startstate).__len__()-1)
        T = T-1
        count +=1
    