def work(case_num):
    n, m = map(int, raw_input().split())
    graph = [ [ 100 for j in range(m) ]  for i in range(n) ]
    target = [ map(int, raw_input().split()) for i in range(n) ]
    
    for i in range(n):
        h = max( target[i] )
        for idx in range(m):
            graph[i][idx] = min(graph[i][idx], h)
        
    for j in range(m):
        h = max( target[x][j] for x in range(n) )
        for idx in range(n):
            graph[idx][j] = min(graph[idx][j], h) 
    
    result = "YES"
    
    for i in range(n):
        for j in range(m):
            if graph[i][j] != target[i][j]:
                result = "NO"
    
    print "Case #%d: %s" % (case_num+1, result)

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        work(t)