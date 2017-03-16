import codejam as gcj
import codejam.iterators as itr

T = gcj.read_input('i')
for t in range(T):
    R, C, M = gcj.read_input('i i i')
    grid = [list('.' * C) for r in range(R)]
    grid[-1][-1] = 'c'

    if R == 1 or M == 0:
        for m in range(M):
            grid[0][m] = '*'
    elif C == 1:
        for m in range(M):
            grid[m][0] = '*'
    elif M == R * C - 1:
        grid = [list('*' * C) for r in range(R)]
        grid[-1][-1] = 'c'
    else:
        gap = (M - (R - 2) * (C - 2)) % 2
        for n, m in itr.multirange(R - 2, C - 2):
            if M > 0:
                grid[n][m] = '*'
                M -= 1

        if gap and M > 0 and R > 2 and C > 2:
            grid[R - 3][C - 3] = '.'
            M += 1

        for c in range(C - 2 - gap):
            if M >= 2:
                grid[R - 1][c] = grid[R - 2][c] = '*'
                M -= 2

        for r in range(R - 2 - gap):
            if M >= 2:
                grid[r][C - 1] = grid[r][C - 2] = '*'
                M -= 2

        if M > 0:
            grid = ['Impossible']

    print 'Case #%i:' % (t + 1)
    for r in grid:
        print ''.join(r)