__author__ = 'Peihong'

def isavailable(board, i, j, R, C):
    if i<0 or i >= R or j < 0 or j >= C:
        return False
    elif board[i][j] != '*':
        return False
    return True

neighbors = [[-1, -1], [0, -1], [1, -1], [-1, 0], [1, 0], [-1, 1], [0, 1], [1, 1]]

def expand(board, pi, pj, R, C):
    newboard = board[:]
    for x in neighbors:
        ni = pi+x[0]
        nj = pj+x[1]
        if isavailable(board, ni, nj, R, C):
            newboard[ni][nj] = '.'
    return newboard

def findfrontier(board, R, C):
    frontier = []
    for i in range(R):
        for j in range(C):
            if board[i][j] != '*':
                flag = False
                for nf in range(len(neighbors)):
                    ni = i+neighbors[nf][0]
                    nj = j+neighbors[nf][1]
                    if isavailable(board, ni, nj, R, C):
                        if board[ni][nj] == '*':
                            flag = True
                if flag:
                    frontier.append([i, j])
    return frontier

def countmines(board, R, C):
    count = 0
    for i in range(R):
        for j in range(C):
            if board[i][j] == '*':
                count = count + 1
    return count

def trysolve(board, R, C, M):
    mines = countmines(board, R, C)
    if mines == M:
        return board
    else:
        frontier = findfrontier(board, R, C)
        for f in frontier:
            row, col = f
            newboard = expand(board, row, col, R, C)
            res = trysolve(newboard, R, C, M)
            if len(res) != 0:
                return res
        return []

def initboard(R, C):
    board = []
    for i in range(R):
        board.append(['*']*C)
    return board

def solve(R, C, M):
    for i in range(R):
        for j in range(C):
            board = initboard(R, C)
            board[i][j] = 'c'
            res = trysolve(board, R, C, M)
            if len(res) != 0:
                return res
    return []

if __name__ == "__main__":
    f = open('C-small-attempt1.in', 'r')
    fout = open('C-small-attempt1.out', 'w')
    cases = int(f.readline())
    for i in range(cases):
        params = map(int, f.readline().split())
        R, C, M = params
        res = solve(R, C, M)

        if len(res) != 0:
            print 'Case #%d:' % (i+1)
            for i in range(R):
                print ''.join(res[i])

            fout.write('Case #%d:\n' % (i+1))
            for j in range(R):
                fout.write(''.join(res[j]))
                fout.write('\n')
        else:
            print 'Case #%d:' % (i+1)
            print 'Impossible'

            fout.write('Case #%d:%s' % (i+1, '\n'))
            fout.write('Impossible\n')

    f.close()
    fout.close()
