def intput():
    return int(input())
def insplit():
    return input().split()
def intsplit():
    a = input().split()
    for i in range(len(a)):
        a[i] = int(a[i])
    return a
def strtolist(a):
    list = []
    for c in a:
        list.append(c)
    return list
def s(a):
    return str(a)

class Graph:
    def __init__(self, line):
        self.graph = {}
        for i in range(len(line)):
            self.graph[i+1] = set([line[i]])

def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph.graph[vertex] - visited)
    return visited   

T = intput()
for t in range(T):
    N = intput()
    line = intsplit()
    g = Graph(line)
    visited = dfs(g, 1)
    for i in range(1,N+1):
        if i not in visited:
            if line[i-1] in visited:
                # if line[i-1] has a free neighbour
                free = True
                for j in visited:
                    if line[j-1] == line[i-1] and line[line[i-1]-1] != j:
                        free = False
                        break
                if free:
                    visited.add(i)
    print("Case #" + str(t+1) + ": " + str(len(visited)))
