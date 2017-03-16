T = int(raw_input())

for t in range(T):
    R, C, M = [int(x) for x in raw_input().split()]
    f = [ [' '] * C for i in range(R)]
    count = [ [0] * C for i in range(R)]

    r = R - 1
    c = C - 1
    R2 = R
    C2 = C
    for _ in range(M):
        f[r][c] = '*'
        if R2 > C2:
            c -= 1
        else:
            r -= 1
        if r < 0 or c < 0:
            if R2 > C2:
                R2 -= 1
            else:
                C2 -= 1
            r = R2 - 1
            c = C2 - 1

    if r == 0 and c > 0 and R > 1:
        f[1][c] = ' '
        f[R2-1][C2-2] = '*'
    if r > 0 and c == 0 and C > 1:
        f[r][1] = ' '
        f[R2-2][C2-1] = '*'

    count = [ [0] * C for i in range(R)]
    for r in range(R):
        for c in range(C):
            if f[r][c] != '*': continue
            if r - 1 >= 0: count[r-1][c] += 1
            if c - 1 >= 0: count[r][c-1] += 1
            if r - 1 >= 0 and c - 1 >= 0: count[r-1][c-1] += 1
            if r + 1 < R: count[r+1][c] += 1
            if c + 1 < C: count[r][c+1] += 1
            if r + 1 < R and c + 1 < C: count[r+1][c+1] += 1
            if r + 1 < R and c - 1 >= 0: count[r+1][c-1] += 1
            if r - 1 >= 0 and c + 1 < C: count[r-1][c+1] += 1

    stack = [(0, 0)]
    while len(stack) > 0:
        (r, c) = stack.pop()
        if r < 0: continue
        if c < 0: continue
        if r >= R: continue
        if c >= C: continue
        if f[r][c] != ' ': continue
        f[r][c] = '.'
        if count[r][c] != 0: continue
        stack.append((r - 1, c))
        stack.append((r + 1, c))
        stack.append((r - 1, c - 1))
        stack.append((r + 1, c - 1))
        stack.append((r - 1, c + 1))
        stack.append((r + 1, c + 1))
        stack.append((r, c - 1))
        stack.append((r, c + 1))

    flag = True
    if f[0][0] == '.':
        f[0][0] = 'c'
        for r in range(R):
            for c in range(C):
                flag = flag and f[r][c] != ' '
    else:
        flag = False

    print 'Case #%d:' % (t + 1)
    if flag:
        for r in f:
            print ''.join(r)
    else:
        print 'Impossible'
