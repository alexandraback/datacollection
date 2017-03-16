from itertools import combinations
MINE = -1

def printboard(board, rows, cols, cr, cc, replace):
    sb = []
    
    for row in range(rows):
        for col in range(cols):
            if (row == cr and col == cc):
                sb.append('c');                
            elif (board[row][col] == MINE):
                sb.append('*')
            elif (replace):
                sb.append('.')               
            else:
                sb.append(str(board[row][col]))
        if row != rows - 1:
            sb.append('\n');
    return ''.join(sb)

def putMine(board, rows, cols, row, col):
    board[row][col] = MINE;
    for r, c in adjacents(row, col, rows, cols):
        if board[r][c] != MINE:
            board[r][c] = board[r][c] + 1

def adjacents(row, col, rows, cols):
    for x in range(-1, 2):
        for y in range(-1, 2):
            r = row + x
            c = col + y
            if r >= 0 and r < rows and c >= 0 and c < cols:
                yield (r, c)            

def getFirst(board, rows, cols):
    for row in xrange(rows):
        for col in xrange(cols):
            if board[row][col] == 0:
                return (row , col);
    return (-1, -1)

def discover(board, reveal, rows, cols, row, col):
    if row < 0 or row >= rows or col < 0 or col >= cols or reveal[row][col]: return
    reveal[row][col] = True
    if board[row][col] == 0:
        discover(board, reveal, rows, cols, row - 1, col - 1);
        discover(board, reveal, rows, cols, row - 1, col);
        discover(board, reveal, rows, cols, row - 1, col + 1);
        discover(board, reveal, rows, cols, row, col - 1);
        discover(board, reveal, rows, cols, row, col + 1);
        discover(board, reveal, rows, cols, row + 1, col - 1);
        discover(board, reveal, rows, cols, row + 1, col);
        discover(board, reveal, rows, cols, row + 1, col + 1);

def countOpen(revealed):
    return sum(map(sum, revealed))    
    
def solve(rows, cols, mines):    
    nums = range(rows*cols)
    if mines == 0:
        board = [[0 for _ in xrange(cols)] for _ in xrange(rows)]
        return printboard(board, rows, cols, 0, 0, True)
    if mines == rows*cols-1:
        board = [[MINE for _ in xrange(cols)] for _ in xrange(rows)]
        board[0][0] = 0
        return printboard(board, rows, cols, 0, 0, True)
    if mines >= rows*cols:
        return 'Impossible'

    for minelist in combinations(nums, mines):
        board = [[0 for _ in xrange(cols)] for _ in xrange(rows)]    
        for mine in minelist:
            row = mine/cols
            col = mine%cols
            putMine(board, rows, cols, row, col)
        
        row, col = getFirst(board, rows, cols)
        #print printboard(board, rows, cols, -1, -1, False)
        #print row, col
        if row < 0 or col < 0:
            continue
        revealed = [[False for _ in xrange(cols)] for _ in xrange(rows)]
        discover(board, revealed, rows, cols, row, col)
        #print printboard(revealed, rows, cols, -1, -1, False)
        #print countOpen(revealed), rows*cols - mines
        if  countOpen(revealed) == rows*cols - mines:
            return printboard(board, rows, cols, row, col, True)
        
    return 'Impossible'


def main():
    filename = 'input.in'
    outfilename = 'output.out'
    with open(filename) as infile:
        with open(outfilename, 'w+') as outfile:
          numcases = int(infile.readline())
          for case in xrange(1, numcases+1):
            rows, cols, mines = map(int, infile.readline().split())
            outfile.write('Case #{}:\n'.format(case))
            outfile.write(solve(rows, cols, mines) + '\n')


if __name__ == "__main__":
    main()
