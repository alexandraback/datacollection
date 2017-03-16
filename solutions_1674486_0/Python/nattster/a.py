from fractions import Fraction
def read_ints():
    a = raw_input().split()
    return [int(x) for x in a]

def read_int():
    return read_ints()[0]

def solve():
    N = read_int()
    edges = []
    for i in range(N):
        val = read_ints()
        edges.append([(x-1) for x in val[1:]])
    visited = [-1] * N  
    tree = [0] * N
    def bfs(node, tree_index):
        if visited[node] != -1:
            return
        level = 0
        queue = [node]
        visited[node] = level
        tree[node] = tree_index
        while len(queue) > 0:
            node = queue.pop(0)
            for e in edges[node]:
                if visited[e] == -1 and e not in queue:
                    visited[e] = visited[node]+1
                    tree[e] = tree_index
                    queue.append(e)
    def dfs(node, level=0):
        if visited[node] != -1:
            return False
        visited[node] = level
        for e in edges[node]:
            if visited[e] == level:
                return True
            else:
                val = dfs(e, level)
                if val == True: return True
        return False

    for i in range(N):
        visited = [-1] * N  
        if dfs(i, i):
            return "Yes"
    return "No"
    """
    bfs(i, i)
    # check for crossing edge in same depth
    for i in range(N):
        for e in edges[i]:
            if (visited[i] == visited[e]
                and tree[i] == tree[e]):
                return 'Yes'
    return 'No'
    """
if __name__ == '__main__':
    T = read_int()
    for i in range(T):
        print 'Case #%d: %s' % (i+1, solve())
