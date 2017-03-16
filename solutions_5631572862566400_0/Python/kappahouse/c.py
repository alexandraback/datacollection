# BFFs

def bffs(p):
    loopm = {}
    loop = [-1] * (len(p))
    def find_loop(c, visited):
        if loop[c] >= 0:
            return -1
        if visited[c]:
            loop[c] = c
            loopm[c] = [c]
            return c
        visited[c] = True
        x = find_loop(p[c], visited)
        if x == -1 or c == x:
            return -1
        loop[c] = x
        loopm[x].append(c)
        return x

    for i in range(len(p)):
        if loop[i] < 0:
            visited = [False] * len(p)
            find_loop(i, visited)
    children = [[] for i in range(len(p))]
    for i in range(len(p)):
        if loop[i] < 0:
            children[p[i]].append(i)

    def max_depth(i):
        return 1 + max([0] + [max_depth(c) for c in children[i]])

    ret1 = 0
    ret2 = 0
    for k in loopm:
        if len(loopm[k]) == 2:
            l1 = max_depth(loopm[k][0])
            l2 = max_depth(loopm[k][1])
            ret2 += l1 + l2
        else:
            ret1 = max(ret1, len(loopm[k]))

    return max(ret1, ret2)

cases = int(raw_input())
for case in range(1, cases + 1):
    n = int(raw_input())
    p = map(lambda s: int(s) - 1, raw_input().split(' '))
    print "Case #" + str(case) + ": " + str(bffs(p))
