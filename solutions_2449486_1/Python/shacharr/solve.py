import fileinput

def board_cutable(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            cell = board[i][j]
            if max(board[i]) > cell and max(board[x][j] for x in range(len(board))) > cell:
                return "NO"
    return "YES"

def input_board(it, num_rows):
    board = []
    for i in range(num_rows):
        board.append([int(x) for x in it.next().split()])
    return board

def main():
    it = fileinput.input()
    num_cases = int(it.next())
    for i in range(num_cases):
        (num_rows, num_cols) = [int(x) for x in it.next().split()]
        board = input_board(it, num_rows)
        print "Case #%d: %s" %(i+1, board_cutable(board))

if __name__ == "__main__":
    main()
