##input = open('A-sample-input.txt', 'r')
##output = open('A-sample-output.txt', 'w')

input = open('A-small-attempt0.in', 'r')
output = open('A-small.out', 'w')

##input = open('A-large.in', 'r')
##output = open('A-large.out', 'w')

def check(char, board):
    new_board = []
    target = char * 4
    for row in board:
        new_board.append(row.replace('T', char))
    for i in range(4):
        if new_board[i] == target:
            return True
        column_string = ""
        for row in range(4):
            column_string += new_board[row][i]
        if column_string == target:
            return True
    diag_string_a = ""
    diag_string_b = ""
    for i in range(4):
        diag_string_a += new_board[i][i]
        diag_string_b += new_board[i][3-i]
    if diag_string_a == target or diag_string_b == target:
        return True
    return False
        

def solve(board):
    if check('X', board):
        return 'X won'
    if check('O', board):
        return 'O won'
    for row in board:
        if '.' in row:
            return "Game has not completed"
    return "Draw"

def main():
    num_cases = int(input.readline().strip())
    for case in range(1, num_cases+1):
        board = []
        for i in range(4):
            board.append(input.readline().strip())
        input.readline()
##        if case == 1:
        solution = solve(board)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
