for i in range(1, input()+1):
    R, C, M = map(int, raw_input().split())
    print 'Case #%d:' % i#, R, C, M

    if R * C == M + 1:
        print 'c' + '*' * (C - 1)
        for x in range(R-1):
            print '*' * C
        continue

    if R == 1:
        print '*' * M + '.' * (C-M-1) + 'c'
        continue

    if C == 1:
        print '*\n' * M + '.\n' * (R-M-1) + 'c'
        continue

    if M > R*C-4:
        print 'Impossible'
        continue

    t = []
    for i in range(R-2):
        if C <= M:
            t.append('*' * C)
            M -= C
        else:
            if C-M == 1:
                t.append('*' * (M - 1) + '.' * (C-M+1))
                M = 1
            else:
                t.append('*' * M + '.' * (C-M))
                M = 0

    if M % 2:
        if t and t[-1].endswith('***') and ((M+3) + 6) <= 2*C:
            M += 3
            t[-1] = t[-1][:-3] + '...'
        elif t and t[-1].endswith('*..') and ((M+1) + 6) <= 2*C:
            M += 1
            t[-1] = t[-1][:-3] + '...'
        else:
            print 'Impossible'
            continue

    if t:
        print '\n'.join(t)
    M1 = M / 2

    if (C - 2) <= M1:
        print '*' * (C - 2) + '..'
    else:
        print '*' * M1 + '.' * (C-2-M1) + '..'
        M = 0

    if (C - 2) <= M1:
        print '*' * (C - 2) + '.c'
    else:
        print '*' * M1 + '.' * (C-2-M1) + '.c'
