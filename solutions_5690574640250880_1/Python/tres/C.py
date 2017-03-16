def colourRest(board, N, R, C):
    for i in range(2, R):
        for j in range(2, C):
            if N <= 0: return
            board[i][j] = '.'
            N -= 1

for t in range(1,int(input())+1):
    R, C, M = map(int,input().split())
    N = R * C - M
    print('Case #{0}:'.format(t))
    rotate = False
    possible = True
    if R > C:
        R, C = C, R
        rotate = True
    board = [['*'] * C for _ in range(R)]
    if N == 1:
        pass
    elif R == 1:
        for i in range(1,N): board[0][i] = '.'
    elif R == 2:
        if N % 2 == 0 and N >= 4:
            for i in range(N // 2): board[0][i] = board[1][i] = '.'
        else:
            possible = False
    else:
        if N in {2, 3, 5, 7}:
            possible = False
        else:
            odd = N % 2 == 1
            if odd:
                N -= 1
            bonus = 2 if N >= 8 else 0
            N -= bonus
            top = min(2 * C, N)
            N -= top
            left = min(2 * (R - 3), N)
            N -= left
            if bonus == 2: board[2][0] = board[2][1] = '.'
            for i in range(top // 2): board[0][i] = board[1][i] = '.'
            for i in range(3, 3 + left // 2): board[i][0] = board[i][1] = '.'
            colourRest(board, N+1 if odd else N, R, C)
            
    if possible:
        board[0][0] = 'c'
        for row in (zip(*board) if rotate else board): print(''.join(row))
        mines = 0
        for i in range(R):
            for j in range(C):
                if board[i][j] == '*':
                    mines += 1

        assert M == mines
    else:
        print('Impossible')
