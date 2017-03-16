# board === list(string[0:4])[0:4]
def load_boards(path):
    with open(path) as f:
        n=int(f.readline())
        boards=[]
        lines=f.readlines(5)
        lines=[l.strip() for l in lines]
        for i in xrange(n):
            boards.append(lines[i*5:i*5+4])
    return boards


def all(lst):
    for e in lst:
        if not e:
            return False
    return True

def get_line_outcome(line):
    if all([(e=='X' or e=='T') for e in line]):
        return 'X'
    if all([(e=='O' or e=='T') for e in line]):
        return 'O'
    return None
def get_board_outcome(board):
    for r in range(4): #check rows
        out=get_line_outcome([board[r][i] for i in range(4)])
        if out:
            return out
    for c in range(4): #check columns
        out=get_line_outcome([board[i][c] for i in range(4)])
        if out:
            return out
    out=get_line_outcome([board[i][i] for i in range(4)]) #check diagonals
    if out:
        return out
    out=get_line_outcome([board[i][3-i] for i in range(4)])
    if out:
        return out
    for r in range(4): # check if finished
        if any([e=='.' for e in board[r]]):
            return 'NC'
    return 'D'

statuses={'X':'X won','O':'O won','D':'Draw','NC':'Game has not completed'}
def save_outcomes(path, outcomes):
    with open(path,'w') as f:
        for n,o in enumerate(outcomes):
            f.write("Case #{0}: {1}\n".format(n+1,statuses[o]))

def process(path_in, path_out):
    boards=load_boards(path_in)
    outcomes=[get_board_outcome(b) for b in boards]
    save_outcomes(path_out, outcomes)