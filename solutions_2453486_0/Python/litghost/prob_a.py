import numpy

DOT = 0
X = 1
O = 2
T = 3

SYMBOLS = {
    '.': DOT,
    'X': X,
    'O': O,
    'T': T,
    }
    
REV_SYMBOLS = dict((v, k) for k, v in SYMBOLS.iteritems())

def read_boards(f):
    itr = iter(f)
    
    T = int(itr.next())
    
    first = True
    
    for _ in xrange(T):
        if not first:
            itr.next()
        first = False
        
        arr = numpy.zeros((4,4), numpy.uint8)
        for row in xrange(4):
            arr[row, :] = map(lambda v: SYMBOLS[v], itr.next()[:4])
            
        yield arr
        
def is_winner(four):
    if all(four[0] == four) and four[0] != DOT:
        return four[0]

def solve_board_inner(board):
    for i in xrange(4):
        v = is_winner(board[i, :])
        if v: 
            return v

        v = is_winner(board[:, i])
        if v:
            return v
           
    v = is_winner(numpy.array([board[i, i] for i in xrange(4)]))
    if v:
        return v
    
    v = is_winner(numpy.array([board[i, 3-i] for i in xrange(4)]))
    if v:
        return v
        
def replace_t(board, v):
    board = numpy.array(board)
    board[board == T] = v
    return board
        
def solve_board(board):
    v = solve_board_inner(replace_t(board, X))
    if v:
        return v
        
    v = solve_board_inner(replace_t(board, O))
    if v:
        return v
        
    if (board[:] == DOT).any():
        return DOT
    
    return T
    
def format_msg(result):
    return {
        X: 'X won',
        O: 'O won',
        DOT: 'Game has not completed',
        T: 'Draw',
        }[result]
        
def solve(f):
    for idx, board in enumerate(read_boards(f)):
        print 'Case #%d: %s' % (idx+1, format_msg(solve_board(board)))
        
if __name__ == '__main__':
    import sys, traceback, pdb
    try:
        solve(open(sys.argv[1]))
    except:
        type, value, tb = sys.exc_info()
        traceback.print_exc()
        pdb.post_mortem(tb)
