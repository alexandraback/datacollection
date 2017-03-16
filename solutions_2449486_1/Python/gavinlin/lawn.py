def read(n, m):
    board = []
    for i in xrange(0,n):
        line = raw_input().split(" ")
        board+=[[ int(x) for x in line ]]
        
    return board

def max_v(board):
    maxv = list(board[0])
    for row in board:
        for i in xrange(0,len(row)):
            if row[i]>maxv[i]:
                maxv[i] = row[i]
            
    return maxv

def check(board, h, v):
    
    for i in xrange(0, len(board)):
        for j in xrange(0, len(board[i])):
            if board[i][j]<h[i] and board[i][j]<v[j]:
                return "NO"

    return "YES"

# Main
t = int(raw_input())

for i in xrange(0,t):
    n, m = raw_input().split(" ")
    n, m = int(n), int(m)

    board = read(n,m)
    
    maxh = [ max(line) for line in board ]
    maxv = max_v(board)
    print "Case #%d:" % (i+1), check(board, maxh, maxv)
  
