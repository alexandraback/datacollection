def diamond(graph):
    for start in graph:
        queue = [start]
        path = []
        while queue:
            node = queue.pop(0)
            if node in path:
                return True
            else:
                path.append(node)
                queue += graph[node]
    return False

if __name__ == '__main__':
    T = int(raw_input())
    for i in xrange(T):
        N = int(raw_input())
        graph = {}
        for j in xrange(N):
            ns = map(int, raw_input().split(' '))
            graph[j+1] = ns[1:]
        print "Case #%d:" % (i+1),
        if diamond(graph):
            print "Yes"
        else:
            print "No" 
