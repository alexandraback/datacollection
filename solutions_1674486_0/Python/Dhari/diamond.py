#graph is represented as follows:
#key: number representing node
#value: array representing adjacency with other nodes
#after every iteration, the transitive closure graph is computed
def HasDiamond(adjacency,N):
    from copy import deepcopy
    transClosure = {}
    for i in range(N):
        transClosure[i] = array('I')
           
    for i in range(N):
        for j in range(N):
            transClosure[i].append(adjacency[i][j])

    adjacencyK = deepcopy(transClosure)
        
    #compute uptil adjacency^N checking along the way whether diamond found
    for currentPower in range(2,N+1):
        #compute transClosure for the current power
        adjacencyKcopy = deepcopy(adjacencyK)
        ##print "Copy is",transClosurecopy
        for i in range(N):
            for j in range(N):
                adjacencyK[i][j] = 0
                for k in range(N):
                    adjacencyK[i][j] += adjacencyKcopy[i][k]*adjacency[k][j]
                transClosure[i][j] += adjacencyK[i][j]
                if transClosure[i][j] > 1:
                    return 1
        #print "Modified copy is",adjacencyKcopy        
        #print transClosure        
                
    return 0


def Main(inputfilename,outputfilename):
    inp = open(inputfilename,"r")
    out = open(outputfilename,"w")

    T = int(inp.readline().strip())

    for t in range(T):
        #print "testcase ",t
        N = int(inp.readline().strip())
        adjacency = {}
        for i in range(N):
            adjacency[i] = array('I')
        for i in range(N):    
            for j in range(N):
                adjacency[i].append(0)
            ##print adjacency[i]    
            lineLst = inp.readline().strip().split(" ")
            M = int(lineLst[0])
            for m in range(M):
                otherNode = lineLst[m+1]
                otherNodeId = int(otherNode)-1
                adjacency[i][otherNodeId] = 1
        #print "adjacency is:"
        #print adjacency
        hasDiamond = HasDiamond(adjacency,N)    
        if hasDiamond == 0:
            out.write('Case #'+str(t+1)+': No\n')
        else:
            out.write('Case #'+str(t+1)+': Yes\n')

    inp.close()
    out.close()

from array import array
Main("./code/Problem1/input.txt","./code/Problem1/output.txt")    

    
                    
            
                
            
        
        
