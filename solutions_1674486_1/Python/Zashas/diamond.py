import sys

def dfs(vertex):
    global marks, results

    if marks[vertex]:
        return
    marks[vertex] = 1
    for i in edges[vertex]:
        results[i] += 1
        dfs(i)

sys.setrecursionlimit(1000000)
cases = int(raw_input())
for case in xrange(cases):
    nb_vertices = int(raw_input())
    edges = []
    transform = lambda x: int(x)-1
    for _ in xrange(nb_vertices):
        edges.append(map(transform,raw_input().split()[1:]))
    for i in xrange(len(edges)):
        f = []
        for j in xrange(len(edges[i])):
            if edges[i][j] == i:
                f.append(j)
        f.reverse()
        for s in f:
            edges[i].remove(s)
    done = False
    for i in xrange(nb_vertices):
        marks = [0]*nb_vertices
        results = [0]*nb_vertices
        dfs(i)
        for i in results:
            if i > 1:
                print "Case #%s: Yes"%(case+1)
                done = True
                break
        if done:
            break
    if not done:
        print "Case #%s: No"%(case+1)
