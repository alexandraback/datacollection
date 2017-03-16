#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    R, C, M = (int(i) for i in input().split())
    a = R * C
    if R == 1:
        ans = '*' * M + '.' * (C-M-1) + 'c'
    elif C == 1:
        ans = '*\n' * M + '.\n' * (R-M-1) + 'c'
    elif R == 2:
        if a-M == 1:
            ans = '*' * C + '\n' + '*' * (C-1) + 'c'
        elif a-M == 2:
            ans = 'Impossible'
        elif M % 2:
            ans = 'Impossible'
        else:
            ans = (('*' * (M//2) + '.' * (C-M//2) + '\n') * 2)[:-2] + 'c'
    elif C == 2:
        if a-M == 1:
            ans = '**\n' * (R-1) + '*c'
        elif a-M == 2:
            ans = 'Impossible'
        elif M % 2:
            ans = 'Impossible'
        else:
            ans = ('**\n' * (M//2) + '..\n' * (R-M//2))[:-2] + 'c'
    else:
        if a-M in (2, 3, 5, 7):
            ans = 'Impossible'
        elif a-M == 1:
            ans = ('\n'.join('*' * C for _ in range(R)))[:-1] + 'c'
        else:
            matrix = [list('.' * C) for _ in range(R)]
            for r in range(R-2):
                for c in range(C-2):
                    if M > 0:
                        matrix[r][c] = '*'
                        M -= 1
            for r in range(R-3):
                if M > 0:
                    matrix[r][C-2] = matrix[r][C-1] = '*'
                    M -= 2
            for c in range(C-3):
                if M > 0:
                    matrix[R-2][c] = matrix[R-1][c] = '*'
                    M -= 2
            if M > 0:
                matrix[R-3][C-2] = matrix[R-3][C-1] = '*'
                M -= 2
            if M > 0:
                matrix[R-2][C-3] = matrix[R-1][C-3] = '*'
                M -= 2
            if M == -1:
                matrix[R-3][C-3] = '.'
            matrix[R-1][C-1] = 'c'
            ans = '\n'.join(''.join(i) for i in matrix)
    print("Case #{}:\n{}".format(case, ans))

