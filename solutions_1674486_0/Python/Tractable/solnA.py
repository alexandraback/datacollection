#!/usr/bin/python

def dfs(graph, j, visited):
    # process j and then apply dft
    if visited[j] == False:
        visited[j] = True
        for i in xrange(len(graph[j])):
            gotit = dfs(graph, graph[j][i], visited)
            if gotit == "Yes":
                return "Yes"
    else:
        return "Yes"
    return "No"

if __name__ == "__main__":
    T = int(raw_input()) # T is the no of test cases
    for i in xrange(T):
        N = int(raw_input())  # Number of classes
        graph = [ list() for k in xrange(N+1) ]
        for j in xrange(1, N+1):
            inp = map(int, raw_input().split())
            nbrs = inp[0]
            graph[j].extend(inp[1:])
        # algo to detect cycle w.r.t. every node
        res = "No"
        for j in xrange(1, N+1):
            nbrs = graph[j]
            visited = [ False for k in xrange(N+1) ]
            res = dfs(graph, j, visited)
            if res == "Yes":
                break
        print "Case #" + str(i+1) + ": " + res
