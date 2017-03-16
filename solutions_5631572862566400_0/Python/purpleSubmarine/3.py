t = int(raw_input())

# visited: 0 - not visited; 1 - visited, sitting with BFF
# 2: visited, not sitting with BFF
# g[i] = [j]: j is i's BFF
# h[i] = [j1, j2 ...]: i is j1, ...'s BFF
def mytry(step, cur, start):
    global g, h, ans, visited, n, lst
    #print start, visited
    if (step > n + 1):
        return
    if (step > 1) and (cur == start):
        #print start, ":", step
        if (ans < step - 1):
            #print lst
            ans = step - 1
            
        return
    if (step == 1):
        #print cur
        nxt = g[cur]
        if (g[nxt] == cur):
            visited[nxt] = 1
        else:
            visited[nxt] = 2
        #lst = lst.append(nxt)
        mytry(step + 1, nxt, start)
        #lst = lst.pop(nxt)
        visited[nxt] = 0
        visited[cur] = 2
        for friend in range(1, n + 1):
            if (friend != nxt) and (friend != cur):
                if (friend in h[cur]):
                    visited[friend] = 1
                else:
                    visited[friend] = 2
                #lst = lst.append(friend)
                mytry(step + 1, friend, start)
                visited[friend] = 0
                #lst = lst.pop(friend)
        return
    nxt = g[cur]
    if (visited[nxt] == 0) or (nxt == start):
        if (visited[nxt] == 0):
            if (g[nxt] == cur):
                visited[nxt] = 1
            else:
                visited[nxt] = 2
        if (nxt == start):
            if (visited[start] == 2) and (g[start] != cur):
                return
        #lst = []
        #lst = lst.append(nxt)
        mytry(step + 1, nxt, start)
        #lst = lst.pop(nxt)
        if (nxt != start):
            visited[nxt] = 0
    if (visited[cur] == 1):
        for friend in range(1, n + 1):
            if (friend != nxt) and (friend != cur):
                if (friend != start) and (visited[friend] == 0):
                    if (friend in h[cur]):
                        visited[friend] = 1
                    else:
                        visited[friend] = 2
                    #lst = lst.append(friend)
                    mytry(step + 1, friend, start)
                    #lst = lst.pop(friend)
                    visited[friend] = 0
                if (friend == start):
                    if (visited[start] != 2) or (g[start] == cur):
                    #lst = lst.append(friend)
                        mytry(step + 1, friend, start)
                    #lst = lst.pop(friend)
    return

for p in xrange(1, t + 1):
    n = int(raw_input())
    g = {}
    h = {}
    for i in xrange(1, n + 1):
        h[i] = []
    i = 1
    for s in raw_input().split(" "):
        g[i] = int(s)
        h[int(s)].append(i)
        i += 1
    ans = 1
    for i in xrange(1, n + 1):
        visited = []
        for j in range(1100):
            visited.append(0)
        visited[i] = 1
        lst = []
        mytry(1, i, i)
    print "Case #" + str(p) + ": " + str(ans)
    #print "Case #{}: {}".format(p, ans)
