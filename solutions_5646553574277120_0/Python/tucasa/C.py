def plus_one(x):
    return x + 1


if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        C, D, V = map(int, raw_input().split())
        denominations = set(map(int, raw_input().split()))
        # can = [False] * (V + 1)
        # can[0] = True
        visited = []
        # deno_index = 0
        L = [0] * (V + 1)
        ret = 0
        for i in xrange(1, V + 1):
            if i in denominations:
                visited.append(i)
                L = map(lambda x: x + i, L)
            elif L[i] < i:
                visited.append(i)
                L = map(lambda x: x + i, L)
                # print L[i], i
                ret += 1
            # print L
        # print visited
        # print ret, "aaa"
        print "Case #%d: %d" % (t, ret)

