directions = [
    [-1, -1], [-1, 0], [-1, 1],
    [0, -1],           [0, 1],
    [1,  -1],  [1, 0],  [1, 1],
]

def solve(R, C, M):
    def neighbors(i, j):
        for di, dj in directions:
            if 0 <= (i + di) < R and 0 <= (j + dj) < C:
                yield (i + di, j + dj)

    def neighbors_to_clear(i, j, board):
        return [(ni, nj) for ni, nj in neighbors(i, j) if board[ni][nj] == "*"]

    def clear_board(order):
        to_clear = R * C - M - 1
        board = [["*" for _ in range(C)] for _ in range(R)]
        for i, j in order:
            board[i][j] = "."
            for ni, nj in neighbors_to_clear(i, j, board):
                to_clear -= 1
                board[ni][nj] = "."
        return board, to_clear

    def search(ci, cj):
        nodes = []
        board = []
        to_clear = 1
        nodes.append((ci, cj, []))
        while nodes and to_clear > 0:
            i, j, order = nodes.pop()
            board, to_clear = clear_board(order)
            neworder = order + [(i, j)]
            if to_clear == 0:
                board[ci][cj] = "c"
                return board
            elif to_clear > 0:
                for ni, nj in neighbors_to_clear(i, j, board):
                    board[ni][nj] = "."
                    nodes.append([ni, nj, neworder])

    for i in range(R):
        for j in range(C):
            board = search(i, j)
            if board:
                for row in board:
                    print "".join(row)
                return

    print "Impossible"
    return

T = int(raw_input())
for i in range(1, T + 1):
    R, C, M = map(int, raw_input().split(" "))
    print("Case #%d:" % i)
    solve(R, C, M)
