import sys

def cols(board):
    for col in range(4):
        yield [board[0][col], board[1][col], board[2][col], board[3][col]]
        
def diags(board):
    yield [board[0][0], board[1][1], board[2][2], board[3][3]]
    yield [board[0][3], board[1][2], board[2][1], board[3][0]]
        
T_set = set(['T'])
        
def same(items):
    s = set(items) - T_set
    if len(s) == 1:
        return s.pop()
    if '.' in s:
        return '.'
    return ''

def solve(board):
    dot = False
    for straights in [board, cols(board), diags(board)]:
        for straight in straights:
            s = same(straight)
            if s:
                if s == '.':
                    dot = True
                else:
                    return "%s won" % s
    if dot:
        return "Game has not completed"
    return "Draw" 

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        board = []
        for line in range(4):
            board.append(sys.stdin.readline().rstrip())
        sys.stdin.readline()
        result = solve(board)
        print "Case #%d: %s" % (t + 1, result)
    
if __name__ == '__main__':
    main()
