T = input()
for t in xrange(1, T + 1):
    K, C, S = map(int, raw_input().split(' '))
    s = 'Case #' + str(t) + ':'
    if K == S:
        step = (K ** C) / K
        for i in range(K):
            s += ' ' + str(1 + i * step)
    else:
        s += ' IMPOSSIBLE'
    print s
