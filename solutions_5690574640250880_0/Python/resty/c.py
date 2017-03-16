import sys
f = sys.stdin

click = 'c'

def revert(X):
    if not X:
        return False
    n = len(X)
    m = len(X[0])
    ans = []
    for i in range(m):
        ans.append([])
        t = ans[i]
        for j in range(n):
            t.append(X[j][i])
    return ans

def calc(R, C, M):
    board = [['*'] * C for i in range(R)]
    n = R * C - M
    if n == 1:
        board[0][0] = click
        return board
    if R == 1 or C == 1:
        if R == 1:
            for i in range(n):
                board[0][i] = '.'
            board[0][0] = click

            return board
        else:
            return revert(calc(C, R, M))
        return False
    if R == 2 or C == 2:
        if n % 2 != 0 or n == 2:
            return False
        else:
            if R == 2:
                i = 0
                while n > 0:
                    board[0][i] = '.'
                    board[1][i] = '.'
                    i += 1
                    n -= 2
                board[0][0] = click
                return board
            else:
                return revert(calc(C, R, M))
    if n == 2 or n == 3 or n == 5 or n == 7:
        return False

    if n == 4:
        board[0][0] = '.'
        board[0][1] = '.'
        board[1][0] = '.'
        board[1][1] = '.'
        n = 0

    # dep the result
    i = 0
    while n >= 4 and i < C:
        board[0][i] = '.'
        board[1][i] = '.'
        n -= 2
        i += 1
    i = 2
    while n >= 2 and i < R:
        board[i][0] = '.'
        board[i][1] = '.'
        n -= 2
        i += 1
    i = 2
    while n > 0:
        slot = min(n, C - 2)
        for j in range(slot):
            board[i][2+j] = '.'
        n -= slot
        i += 1
    board[0][0] = click
    return board

def check(board, empty):
    assert board[0][0] == 'c'
    v = [[False] * len(board[0]) for i in range(len(board))]
    R = len(v)
    C = len(v[0])
    v[0][0] = True
    queue = [(0, 0)]
    r = 1
    f = 0
    cnt = 1
    while f < len(queue):
        (x, y) = queue[f]
        f += 1
        for i in range(-1, 2):
            for j in range(-1, 2):
                nx = x + i
                ny = y + j
                if nx >= 0 and nx < R and ny >= 0 and ny < C:
                    if board[nx][ny] != '*' and not v[nx][ny]:
                        cnt += 1
                        v[nx][ny] = 1
                        # test if it is zero
                        zero = True
                        for dx in range(-1, 2):
                            for dy in range(-1, 2):
                                tx = nx + dx
                                ty = ny + dy
                                if tx >= 0 and tx < R and ty >= 0 and ty < C:
                                    if board[tx][ty] == '*':
                                        zero = False
                                        break
                            if not zero:
                                break
                        if zero:
                            queue.append((nx, ny))
    assert cnt == empty, "cnt=%d, empty=%d" % (cnt, empty)

def solve():
    # row col mar
    (R, C, M) = map(int, f.readline().split(' '))
    res = calc(R, C, M)
    if not res:
        print "Impossible"
    else:
        test = 0
        for row in res:
            for j  in row:
                if j == '*':
                    test += 1
            print ''.join(row)

        assert test == M
        check(res, R * C - M)
cases = int(f.readline())
for t in range(cases):
    print "Case #%d:" % (t+1)
    solve()
