import sys

def read_graph(fin):
    N = int(fin.readline())
    g = [[]]
    for i in range(N):
        M = fin.readline().split()
        M = [ int(e) for e in M]
        g.append(M[1:])
    return g

def dfs(g, s, v):
#    print ("dfs(%s, %s, %s)" % (str(g), str(s), str(v)))
#    print "Check %d -> %s" % (s, str(g[s]))
    if v[s]:
        return True
    v[s] = True
    for d in g[s]:
        if dfs(g, d, v):
            return True
    return False
    
def has_diamond(g):
    N = len(g) - 1
    visited = [False for i in range(N+1)]
    for e in g:
        for d in e:
            visited[d] = True
    for i in range(1, N+1):
        if visited[i]:
            continue
#        print "Check i %d" % i
        v = [False for ii in range(N+1)]
        if dfs(g, i, v):
            return True
    return False

if __name__ == "__main__":
    sys.setrecursionlimit(2000)
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        G = read_graph(sys.stdin)
        print "Case #%d: %s" % (i, "Yes" if has_diamond(G) else "No")

            