from Queue import Queue
def isGoalState(state,X,Y):
    
    x = state[0][0]
    y = state[0][1]
    #print x,y
    if x == X and y == Y:
        #print state
        return True
    else:
        return False
        
    
    
def getSuccessors(state):
    x = state[0][0]
    y = state[0][1]
    successers = []
    nextMove = state[1]+1
    #print A
    #N
    successers.append(tuple([tuple([x,y+nextMove]),nextMove,'N']))
    #S
    successers.append(tuple([tuple([x,y-nextMove]),nextMove,'S']))
    #W
    successers.append(tuple([tuple([x-nextMove,y]),nextMove,'W']))
    #E
    successers.append(tuple([tuple([x+nextMove,y]),nextMove,'E']))
    return successers
    
    
    
    

def traverse_path(fromNode):
    def make_path(toNode, graph):
        result = []
        while 'Root' != toNode:
            result.append(toNode)
            toNode = graph[toNode]
        result.reverse()
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
        if isGoalState(current,X,Y):
            return make_path(current, graph)
    return []

if __name__ == "__main__":
    T = int(raw_input())    
    count = 1
    while T>0:
        XY = [int(i) for i in raw_input().strip().split()]
        X = XY[0]
        Y = XY[1]
        startstate = (tuple([0,0]),0,None)
        #print startstate
        ret = traverse_path(startstate)
        path = ""
        for val in ret:
            if val[2]!=None:
                path +=val[2]
        print "Case #"+str(count)+": "+path
        
        T = T-1
        count +=1
    