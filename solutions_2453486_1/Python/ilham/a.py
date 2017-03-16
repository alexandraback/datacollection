def count(line, c):
    return line.count(c) + line.count('T')

def diag(board):
    x = []
    for i in range(4):
        x.append(board[i][i])
    return x

def rdiag(board):
    x = []
    for i in range(4):
        x.append(board[i][3-i])
    return x

def check(board, c):
    tr = zip(*board)
    for i in range(4):
        if count(board[i], c) == 4:
            return 1
    for i in range(4):
        if count(tr[i], c) == 4:
            return 1
    if count(diag(board), c) == 4:
        return 1
    if count(rdiag(board), c) == 4:
        return 1
    return 0

def doit(board):
    if check(board, 'X'):
        return 0
    if check(board, 'O'):
        return 1
    if ''.join(board).count('.') > 0:
        return 2;
    return 3

if __name__ == "__main__":
    import sys
    f = open(sys.argv[1], 'r')
    ans = ["X won", "O won", "Game has not completed", "Draw"]
    n = int(f.readline())
    for i in range(n):
        x = []
        for j in range(4):
            x.append(f.readline())
        f.readline()
        print "Case #{}: {}".format(i + 1, ans[doit(x)])
