import sys

def isWinner(board, player):
    size = len(board)
    seq = player*size

    for row in board:
        if ''.join(row) == seq:
            return True

    for col in xrange(size):
        if ''.join([board[idx][col] for idx in xrange(size)]) == seq:
            return True
        
    if ''.join([board[idx][idx] for idx in xrange(size)]) == seq:
        return True

    if ''.join([board[idx][size-idx-1] for idx in xrange(size)]) == seq:
        return True
    
    return False
        
        
def whoIsWinner(badrd):
    ret = 'Draw'
    t = None

    for row in xrange(len(board)):
        if '.' in board[row]:
            ret = 'Game has not completed'

        try:
            t = (row, board[row].index('T'))
        except:
            ""

    for player in 'O','X':
        if t != None:
            board[t[0]][t[1]] = player

        if isWinner(board, player):
            return '%s won' % player
            
    return ret
    
T = int(sys.stdin.readline().strip())
for case in xrange(1,T+1):
    board = [list(sys.stdin.readline().strip()) for _ in xrange(4)]

    if case<T:
        sys.stdin.readline()

    print 'Case #%d: %s' % (case, whoIsWinner(board))
        
