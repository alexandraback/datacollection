import sys

def read_case(lines):
    board = [lines.next().strip() for _ in range(4)]
    
    try:
        lines.next()
    except StopIteration:
        pass
            
    return board

def read_input(path):
    cases = []
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())

        for i in range(1, 1 + n):
            cases.append((i, read_case(lines)))

    return cases

def check_win(board, player):
    for i in board:
        total = sum([j in (player, 'T') for j in i])
        if total == 4:
            return True
        
    for j in range(4):
        total = sum(board[i][j] in (player, 'T') for i in range(4))
        if total == 4:
            return True
        
    total = sum(board[i][i] in (player, 'T') for i in range(4))
    if total == 4:
        return True

    total = sum(board[i][3 - i] in (player, 'T') for i in range(4))
    if total == 4:
        return True
    
    return False

def check_draw(board):
    return all(['.' not in i for i in board])

def solve(board):
    if check_win(board, 'X'):
        return 'X won'
    elif check_win(board, 'O'):
        return 'O won'
    elif check_draw(board):
        return 'Draw'
    else:
        return 'Game has not completed'

if __name__ == '__main__':
    cases = read_input(sys.argv[1])
    for i, case in cases:
        print 'Case #%d: %s' % (i, solve(case))
