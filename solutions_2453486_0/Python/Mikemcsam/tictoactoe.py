def check_board(board):
    for i in range(4):
        if check_iterator([board[i][j] for j in range(4)],"X") or check_iterator([board[j][i] for j in range(4)],"X"):
            return "X"
        if check_iterator([board[i][j] for j in range(4)],"O") or check_iterator([board[j][i] for j in range(4)],"O"):
            return "O"
    if check_iterator([board[i][i] for i in range(4)],"X") or check_iterator([board[i][3-i] for i in range(4)],"X"):
            return "X"
    if check_iterator([board[i][i] for i in range(4)],"O") or check_iterator([board[i][3-i] for i in range(4)],"O"):
            return "O"
    return None

def check_iterator(row, letter):
    t_count = 0
    letter_count = 0
    for item in row:
        if item == "T":
            t_count+=1
        elif item == letter:
            letter_count+=1
    return letter_count == 4 or letter_count == 3 and t_count == 1
    
    
def score_board(board):
    result = check_board(board)
    if result == "X":
        return "X won"
    if result == "O":
        return "O won"
    else:
        count = 0
        for i in range(4):
            for j in range(4):
                if board[i][j] == "X" or board[i][j] == "O" or board[i][j] == "T":
                    count+=1
        if count == 16:
            return "Draw"
        else:
            return "Game has not completed"
            
            
import sys            
if __name__ == "__main__":
    f = sys.stdin
    tests = int(next(f).strip())
    for i in range(tests):
        if i != 0:
            next(f)
        board = []
        for j in range(4):
            board.append(next(f).strip())
        print("Case #"+str(i+1)+": "+ score_board(board))
         
            