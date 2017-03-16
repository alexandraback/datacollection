T = input()
for t in xrange(1, T + 1):
    K, C, _ = map(int, raw_input().split(' '))
    step = (K ** C) / K
    s = 'Case #' + str(t) + ':'
    for i in range(K):
        s += ' ' + str(1 + i * step)
    print s
