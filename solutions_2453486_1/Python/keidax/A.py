import math


def main():
    fin = open('A-large.in')
    fout = open('output.txt', 'w')
    num_cases = int(fin.readline().strip())

    for i in range(num_cases):
        output_string = 'Case #'+str(i+1)+": "

        game_status = ""
        board = read_board(fin)
        if has_player_won(board, "O"):
            game_status = "O won"
        elif has_player_won(board, "X"):
            game_status = "X won"
        elif is_full(board):
            game_status = "Draw"
        else:
            game_status = "Game has not completed"
        # print output_string
        fout.write(output_string + game_status + '\n')
    fout.close()
    fin.close()


def read_board(file):
    board = []
    for i in range(0, 4):
        line = list(file.readline().strip())
        board.append(line)
    file.readline()
    return board


def is_full(board):
    for row in board:
        for space in row:
            if space == ".":
                return False
    return True


def has_player_won(board, player):
    # test rows
    for row in board:
        rowtest = True
        for space in row:
            if space != player and space != 'T':
                rowtest = False
        if rowtest:
            return True

    # test cols
    for col in range(0, 4):
        coltest = True
        for row in range(0, 4):
            if board[row][col] != player and board[row][col] != 'T':
                coltest = False
        if coltest:
            return True

    # test diags
    diagAtest = True
    for a in range(0, 4):
        if board[a][a] != player and board[a][a] != 'T':
            diagAtest = False
    if diagAtest:
        return True

    diagBtest = True
    for a in range(0, 4):
        if board[a][3-a] != player and board[a][3-a] != 'T':
            diagBtest = False
    if diagBtest:
        return True

    # if true has not been returned so far...
    return False


if __name__ == '__main__':
    main()
