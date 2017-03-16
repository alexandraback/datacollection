import sys

def zeroes(i):
    result = []
    for i in range(0,i):
        result.append(0)
    return result

def DFS(graph, start, visited):
    #print start
    visited[start - 1] = 1 #mark the node as visited
    for node in graph[start]: #For all paths out of the current node
        if (visited[node - 1] == 0): #if the future node hasnt been visited
            DFS(graph, node, visited) #Recurse on the new node
        elif(visited[node - 1] == 1):
            visited[node - 1] = 2
    #print visited
    answer = False
    for i in range(0,len(visited)):
        if(visited[i] == 2):
            answer = True
    return answer

sys.setrecursionlimit(1500)
IN = open('ALargeIn.txt','r')
OUT = open('ALargeOut.txt','w')
tc = int(IN.readline())
for i in xrange(tc):
    classes = int(IN.readline())
    graph = {}
    for j in xrange(classes):
        data = IN.readline().split(' ')
        graph[j+1] = [int(data[x]) for x in range (1,len(data))]
    #print classes
    #print graph

    solution = 'No'
    for j in range(1,classes+1):
        if(DFS(graph, j, zeroes(classes))):
            solution = 'Yes'
            break
    
    print "Case #%i: %s" % (i+1,solution)
    OUT.write("Case #%i: %s\n" % (i+1,solution))
OUT.close()
