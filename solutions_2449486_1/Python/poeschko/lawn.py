import sys

def solve(board):
    row_indices = range(len(board))
    col_indices = range(len(board[0]))
        
    def cols():
        for col in col_indices:
            yield (board[row][col] for row in row_indices)
        
    row_max = map(max, board)
    col_max = [max(col) for col in cols()]
    
    for row in row_indices:
        for col in col_indices:
            val = board[row][col]
            if val < row_max[row] and val < col_max[col]:
                return "NO"
            
    return "YES"

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        N, M = map(int, sys.stdin.readline().rstrip().split())
        board = []
        for n in range(N):
            board.append(map(int, sys.stdin.readline().rstrip().split()))
        result = solve(board)
        print "Case #%d: %s" % (t + 1, result)
    
if __name__ == '__main__':
    main()
