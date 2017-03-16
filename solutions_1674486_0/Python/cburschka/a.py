def dfs_dual(n, adjacency, start):
    reachable = [False]*n
    stack = start, None
    while stack:
        current, stack = stack
        for neighbour in adjacency[current]:
            if reachable[neighbour]:
                return True
            else:
                reachable[neighbour] = True
                stack = neighbour, stack
    return False

def diamond(n, adjacency):
    return any([dfs_dual(n, adjacency, x) for x in range(n)])

n = int(raw_input())
for i in range(n):
    size = int(raw_input())
    adjacency = []
    for j in range(size):
        adjacency.append(map(lambda x:int(x)-1, raw_input().split()[1:]))
    result = ['No', 'Yes'][diamond(size, adjacency)]
    print "Case #%d: %s" % (i+1, result)
