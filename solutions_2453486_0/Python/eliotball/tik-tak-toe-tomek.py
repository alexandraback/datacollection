def winner(line):
    line = line.rstrip()
    if "".join(sorted(line)) == "OOOO" or "".join(sorted(line)) == "OOOT":
        return "O won"
    if "".join(sorted(line)) == "XXXX" or "".join(sorted(line)) == "TXXX":
        return "X won"
    return None

def board_outcome(board):
    print("".join(board))
    # Check for a player winning on the diagonal
    if winner(board[0][0] + board[1][1] + board[2][2] + board[3][3]) != None:
        return winner(board[0][0] + board[1][1] + board[2][2] + board[3][3])
    # Check for a player winning on the antidiagonal
    if winner(board[0][3] + board[1][2] + board[2][1] + board[3][0]) != None:
        return winner(board[0][3] + board[1][2] + board[2][1] + board[3][0])
    # Check for a player winning on a row
    for row in range(4):
        if winner(board[row]) != None:
            return winner(board[row])
    # Check for a player winning on a column
    for column in range(4):
        if winner(board[0][column] + board[1][column] + board[2][column] + board[3][column]) != None:
            return winner(board[0][column] + board[1][column] + board[2][column] + board[3][column])
    # Nobody won, so check if there are any gaps showing the game to be incomplete
    for i in "".join(board):
        if i == ".":
            return "Game has not completed"
    # No gaps so it's a draw
    return "Draw"

fin = open("input.txt", "r")
fout = open("output.txt", "w")

t = int(fin.readline())

for i in range(t):
    board = [fin.readline() for i in range(5)]
    fout.write("Case #" + str(i + 1) + ": " + board_outcome(board) + "\n")

fin.close()
fout.close()
