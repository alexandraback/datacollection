#!/usr/bin/env python3
T = int(input())

for case in range(1, T+1):
    print('Case #{}: '.format(case))
    R, C, M = map(int, input().split())
    if R == 1:
        for i in range(C-1):
            if M > 0:
                print('*', end='')
                M -= 1
            else:
                print('.', end='')
        print('c')
    elif C == 1:
        for i in range(R-1):
            if M > 0:
                print('*')
                M -= 1
            else:
                print('.')
        print('c')
    elif M+1 == R*C:
        for i in range(R):
            for j in range(C):
                if i+1 == R and j+1 == C:
                    print('c', end='')
                else:
                    print('*', end='')
            print()
    elif M <= R*C - 4 and M != R*C - 5 and M != R*C - 7 and not (M%2 == 1 and (R == 2 or C == 2)):
        board = [['.' for y in range(C)] for x in range(R)]
        board[R-1][C-1] = 'c'
        lastx, lasty = 0, 0
        if M > 0 and R < C:
            startj = 0
            while M > 0 and C-startj > R:
                for i in range(R):
                    if M == 0:
                        break
                    board[i][startj] = '*'
                    lastx, lasty = i, startj
                    M -= 1
                startj += 1

            if M == 0:
                if lastx+2 == R:
                    board[lastx][lasty] = '.'
                    board[0][lasty+1] = '*'
            else:
                for i in range(R):
                    if M > 0:
                        board[i][startj+i] = '*'
                        lastx, lasty = i, startj+i
                        M -= 1
                    for j in range(1, R-i):
                        if M > 0:
                            board[i][startj+i+j] = '*'
                            lastx, lasty = i, startj+i+j
                            M -= 1
                    for j in range(1, R-i):
                        if M > 0:
                            board[i+j][startj+i] = '*'
                            lastx, lasty = i+j, startj+i
                            M -= 1

                if lastx+2 == R:
                    board[lastx][lasty] = '.'
                    board[lasty-startj+1][lasty+1] = '*'
                if lasty+2 == C:
                    board[lastx][lasty] = '.'
                    board[lastx+1][startj+lastx] = '*'
        elif M > 0:
            starti = 0
            while M > 0 and R-starti > C:
                for j in range(C):
                    if M == 0:
                        break
                    board[starti][j] = '*'
                    lastx, lasty = starti, j
                    M -= 1
                starti += 1
            if M == 0:
                if lasty+2 == C:
                    board[lastx][lasty] = '.'
                    board[lastx+1][0] = '*'
            else:
                for j in range(C):
                    if M > 0:
                        board[starti+j][j] = '*'
                        lastx, lasty = starti+j, j
                        M -= 1
                    for i in range(1, C-j):
                        if M > 0:
                            board[starti+j][j+i] = '*'
                            lastx, lasty = starti+j, j+i
                            M -= 1
                    for i in range(1, C-j):
                        if M > 0:
                            board[starti+j+i][j] = '*'
                            lastx, lasty = starti+j+i, j
                            M -= 1

                if lastx+2 == R:
                    board[lastx][lasty] = '.'
                    board[starti+lasty+1][lasty+1] = '*'
                if lasty+2 == C:
                    board[lastx][lasty] = '.'
                    board[lastx+1][lastx-starti] = '*'

        print('\n'.join(map(''.join, board)))
    else:
        print("Impossible")
