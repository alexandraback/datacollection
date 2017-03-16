if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    for casenum in range(input()):
        def solution_exists(board, target, opened=1):
            if opened == target:
                return True
            if opened > target:
                return False

            width = len(board[0])
            height = len(board)

            for r in range(len(board)):
                for c in range(len(board[0])):
                    if not board[r][c]:
                        continue

                    tl = board[max(0, r - 1)][max(0, c - 1)]
                    to = board[max(0, r - 1)][c]
                    tr = board[max(0, r - 1)][min(width - 1, c + 1)]
                    ri = board[r][min(width - 1, c + 1)]
                    br = board[min(height - 1, r + 1)][min(width - 1, c + 1)]
                    bo = board[min(height - 1, r + 1)][c]
                    bl = board[min(height - 1, r + 1)][max(0, c - 1)]
                    le = board[r][max(0, c - 1)]

                    if not tl * to * tr * ri * br * bo * bl * le:
                        # open neighbours
                        if not board[max(0, r - 1)][max(0, c - 1)]:
                            board[max(0, r - 1)][max(0, c - 1)] = 1
                            opened += 1
                        if not board[max(0, r - 1)][c]:
                            board[max(0, r - 1)][c] = 1
                            opened += 1
                        if not board[max(0, r - 1)][min(width - 1, c + 1)]:
                            board[max(0, r - 1)][min(width - 1, c + 1)] = 1
                            opened += 1
                        if not board[r][min(width - 1, c + 1)]:
                            board[r][min(width - 1, c + 1)] = 1
                            opened += 1
                        if not board[min(height - 1, r + 1)][min(width - 1, c + 1)]:
                            board[min(height - 1, r + 1)][min(width - 1, c + 1)] = 1
                            opened += 1
                        if not board[min(height - 1, r + 1)][c]:
                            board[min(height - 1, r + 1)][c] = 1
                            opened += 1
                        if not board[min(height - 1, r + 1)][max(0, c - 1)]:
                            board[min(height - 1, r + 1)][max(0, c - 1)] = 1
                            opened += 1
                        if not board[r][max(0, c - 1)]:
                            board[r][max(0, c - 1)] = 1
                            opened += 1

                        return solution_exists(board, target, opened)


        r, c, m = [int(i) for i in raw_input().split()]
        print 'Case #%d:' % (casenum + 1)

        for y in range(r):
            for x in range(c):
                board = [[0] * c for i in range(r)]
                board[y][x] = 1
                if solution_exists(board, r * c - m):
                    for i in range(r):
                        for k in range(c):
                            if i == y and k == x:
                                sys.stdout.write('c')
                                continue
                            if board[i][k]:
                                sys.stdout.write('.')
                                continue
                            sys.stdout.write('*')
                        print
                    break
                else:
                    pass
            else:
                continue
            break
        else:
            print 'Impossible'
            continue
