times = input()

def process_board(board):
    dot = is_dot(board) ####
#    print 'dot is', dot
    result = None
    strings = []
    for i in range(4):
        strings.append(board[i])
    for i in range(4):
        string = []
        for j in range(4):
            string.append(board[j][i])
        strings.append(string)
    string1 = []
    string2 = []
    for i in range(4):
        string1.append(board[i][i])
        string2.append(board[i][3-i])
    strings.append(string1)
    strings.append(string2)
    
#    print 'strings', strings
    
    for i in range(len(strings)):
        ans = process_string(strings[i])    ####
        if ans in ['X','O']:
            return dot, ans
        
    return dot, ans
            
def is_dot(board):
#    print 'board', board
    ans = False
    for i in range(4):
        for j in range(4):
            if board[i][j] == '.':
                ans = True
    return ans

def process_string(string):
    string.sort()
    correcto = [ ['O', 'O', 'O', 'O'], ['O', 'O', 'O', 'T']]
    correctx = [['T', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'] ]
    if string in correcto:
        return 'O'
    if string in correctx:
        return 'X'
    return

for time in range(times):
    board = []
    for i in range(4):
        board.append(list(raw_input()))
#    print board
    raw_input()

    dot, result = process_board(board)
    if not result:
        if dot == True:
            print 'Case #%d: Game has not completed' % (time+1)
        else:
            print 'Case #%d: Draw' % (time+1)
    else:
        print 'Case #%d: %s won' % ((time+1),result)
