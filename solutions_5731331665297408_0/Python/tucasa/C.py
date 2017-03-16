def dfs(v, is_return=False):
    global min_ret
    if not is_return:
        # print ''.join(city_zip[idx] for idx in stack), min_ret
        if ''.join(city_zip[idx] for idx in stack) > min_ret:
            return
        stack.append(v)
        visited[v] = True
    # print stack

    if len(stack) == N:
        # ret.append(''.join(city_zip[idx] for idx in stack))
        min_ret = min(min_ret, ''.join(city_zip[idx] for idx in stack))
        visited[v] = False
        stack.pop()
        return
    for u in xrange(N):
        if v == u:
            continue
        if edges[v][u] == 1:
            if not visited[u]:
                can_return[u] = v
                dfs(u)
    if can_return[v] != -1:
        tmp = can_return[v]
        dfs(tmp, True)
    if not is_return:
        stack.pop()
        visited[v] = False


if __name__ == '__main__':
    T = input()
    for t in xrange(1, T + 1):
        N, M = map(int, raw_input().split())
        city_zip = [0] * N
        for i in xrange(N):
            city_zip[i] = raw_input()
        edges = [[0] * N for _ in xrange(N)]
        for i in xrange(M):
            x, y = map(int, raw_input().split())
            edges[x-1][y-1] = edges[y-1][x-1] = 1
        min_ret = '9' * 50
        for i in xrange(N):
            stack = []
            visited = [False] * N
            can_return = [-1] * N
            dfs(i)
        print "Case #%d: %s" % (t, min_ret)