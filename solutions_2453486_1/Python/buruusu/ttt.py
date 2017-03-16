import sys

D = 4

LINES = list()
LINES.append([(i, i) for i in range(4)])
LINES.append([(i, 3-i) for i in range(4)])
for i in range(4):
    LINES.append([(i, j) for j in range(4)])
    LINES.append([(j, i) for j in range(4)])


def read_input():
    lines = sys.stdin.read().splitlines()
    n = int(lines[0])
    boards = list()
    for i in range(n):
        b = list()
        x = 1+i*(D+1)
        boards.append(lines[x:x+D])
    return boards

def check_winner(boards):
    for b in boards:
        winner = check_winner_board(b)
        if winner:
            outcome = '%s won' % winner
        else:
            draw = not check_complete_board(b)
            outcome = 'Draw' if draw else 'Game has not completed'
        output_case(outcome)

case = 1
def output_case(outcome):
    global case
    print 'Case #%d: %s' % (case, outcome)
    case += 1

def flatten_board(board):
    return [item for sublist in board for item in sublist]
    
def check_complete_board(board):
    return '.' in flatten_board(board)
    
def check_winner_board(board):
    w = False
    for line in LINES:
        w = check_winner_line(board, line)
        if w:
            return w
    return False

def check_winner_line(board, line):
    win = []
    for c in line:
        s = board[c[0]][c[1]]
        if '.' == s:
            return False
        if s in 'XO':
            if len(win) < 1 or win[-1] == s:
                win += s
            else:
                return False
        # Ignore T..
    # If we get here, we have a winner
    return win[0]
    
boards = read_input()
check_winner(boards)
