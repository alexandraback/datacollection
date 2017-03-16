import fileinput

def combine_cells(x,y):
    if x == y:
        return x
    if x == "T":
        return y
    if y == "T":
        return x
    return "."

def check_board(board):
    #rows
    for i in range(4):
        winner = reduce(combine_cells, board[i], "T")
        if winner != ".":
            return winner
    #colomns
    for i in range(4):
        winner = reduce(combine_cells, [board[x][i] for x in range(4)], "T")
        if winner != ".":
            return winner
    #diags
    winner = reduce(combine_cells, [board[x][x] for x in range(4)], "T")
    if winner != ".":
        return winner
    winner = reduce(combine_cells, [board[x][3-x] for x in range(4)], "T")
    if winner != ".":
        return winner
    #tie/incomplete?
    for i in range(4):
        if "." in board[i]:
            return "."
    return "T"

def stringify_res(res):
    if res == "X":
        return "X won"
    if res == "O":
        return "O won"
    if res == "T":
        return "Draw"
    if res == ".":
        return "Game has not completed"

def get_board(it):
    board = []
    for i in range(4):
        board.append(it.next().strip())
    return board

def main():
    it = fileinput.input()
    num_cases = int(it.next())
    for i in range(num_cases):
        board = get_board(it)
        it.next()
        print "Case #%d: %s" %(i+1, stringify_res(check_board(board)))

if __name__ == "__main__":
    main()
