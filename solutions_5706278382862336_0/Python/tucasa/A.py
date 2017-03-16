def dfs(bunsi, bunbo, generate):
    if bunsi == bunbo:
        return generate
    if bunbo % 2:
        return -1
    bunbo /= 2
    if bunsi > bunbo:
        if dfs(bunsi % bunbo, bunbo, generate + 1) != -1:
            return generate + 1
        else:
            return -1
    else:
        return dfs(bunsi, bunbo, generate + 1)

if __name__ == '__main__':
    T = input()
    for t in xrange(1, T + 1):
        a, b = map(int, raw_input().split('/'))
        stack = []
        ret = dfs(a, b, 0)
        if ret == -1:
            print "Case #%d: impossible" % t
        else:
            print "Case #%d: %d" % (t, ret)
