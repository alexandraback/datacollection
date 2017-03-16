T = input()
for t in range(T):
    l = raw_input().split(' ')
    n = int(l[0])
    p = []
    for i in range(n + 1):
        p.append(int(l[1][i]))
    a = 0
    c = 0
    for i in range(n + 1):
        if c >= i:
            c += p[i]
        else:
            a += i - c
            c = i
            c += p[i]
    print 'Case #%d: %d' % (t + 1, a)
