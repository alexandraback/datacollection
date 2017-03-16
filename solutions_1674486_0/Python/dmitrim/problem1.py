def solve(g):
    n = len(g)
    for i in range(n):
        seen = [x for x in range(n) if x != i]
        q = [i]
        while q:
            x = q.pop()
            for j in range(n):
                if g[x][j]:
                    if j in seen:
                        seen.remove(j)
                        q.append(j)
                    else:
                        return "Yes"
    return "No"

g = open("output.txt", 'w')
with open("A-small-attempt0.in") as f:
    N = int(f.readline())
    for I in range(N):
        s = f.readline().split()
        n = int(s[0])
        graph = [[0]*n for i in range(n)]
        for i in range(0,n):
            s = f.readline().split()
            m = int(s[0])
            for j in range(1,m+1):
                graph[i][int(s[j])-1] = 1

        res = solve(graph)
        out = "Case #%d: %s\n" % (I+1, res)
        print out
        g.write(out)

g.close()

