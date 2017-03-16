def solve_tictoe(board):
    """solve a tic_toe of 4x4"""
    has_empty = False 
    row = [0,0,0,0]
    col = [0,0,0,0]
    diagon = [0,0]
    t_pos = None
    for r in range(0, len(board)):
        for c in range(0, len(board[r])):
            #check row
            val = board[r][c]

            if board[r][c] == 'X': 
                row[r] += 1
                col[c] += 1
                if r == c:
                    diagon[0] += 1
                elif c == 3 - r:
                    diagon[1] += 1
                    
            elif board[r][c] == 'O':
                row[r] += -1
                col[c] += -1
                if r == c: 
                    diagon[0] += -1
                elif c == 3 - r:
                    diagon[1] += -1
            elif board[r][c] == '.':
                has_empty = True
            elif board[r][c] == 'T':
                t_pos = (r,c)
    check = [] 
    check.append(row)
    check.append(col)
    check.append(diagon)

    for c in check:
        for v in c:
            if abs(v) == 4:
                return 'X won' if v > 0 else 'O won'
    if t_pos is not None:
        if abs(row[t_pos[0]]) == 3:
            return 'X won' if row[t_pos[0]] > 0 else 'O won'
        elif abs(col[t_pos[1]]) == 3:
            return 'X won' if col[t_pos[1]] > 0 else 'O won'
        elif t_pos[0] == t_pos[1] and abs(diagon[0]) == 3:
            return 'X won' if diagon[0] > 0 else 'O won'
        elif t_pos[0] == 3 - t_pos[1] and abs(diagon[1]) == 3:
            return 'X won' if diagon[1] > 0 else 'O won'
    if has_empty:
        return 'Game has not completed'
    else:
        return 'Draw'

if __name__=="__main__":
    #solve tic tac toe 
    with open("input_large") as f:
        content = f.readlines()

    N = int(content[0])
    for case in range(0,N):
        board = []
        for r in range(1,1+4):
            line = content[case*5 + r].strip()
            board.append(line)
        print "Case #" + str(case+1) + ": " + solve_tictoe(board)


