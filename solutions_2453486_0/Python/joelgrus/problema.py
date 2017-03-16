infile = "A-small-attempt0.in"
outfile = "A-small-attempt0.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")#

from collections import defaultdict

def winner(board,coords):
    xs = os = ts = 0
    for (i,j) in coords:
        c = board[i][j]
        if c == 'X':
            xs += 1
        elif c == 'O':
            os += 1
        elif c == 'T':
            ts += 1
    
    if xs + ts >= 4:
        return 'X'
    elif os + ts >= 4:
        return 'O'
    else:
        return None

rows = [ [(i,j) for j in range(4)] for i in range(4)]
columns = [ [(i,j) for i in range(4)] for j in range(4)]
diags = [ [(0,0),(1,1),(2,2),(3,3)],
          [(0,3),(1,2),(2,1),(3,0)] ]

all_coords = rows + columns + diags

T = int(lines[0])
lines = lines[1:]

for loop in range(T):
    result = None
    board_lines = lines[:4]
    lines = lines[5:]
    board = [ [c for c in line]
                for line in board_lines]
    #print board
    for coords in all_coords:
        check = winner(board,coords)
        #print check,coords
        if check == 'X':
            result = 'X won'
            break
        elif check == 'O':
            result = 'O won'
            break
    if not result:
        blanks = [c for row in board for c in row if c == '.']
        if blanks:
            result = 'Game has not completed'
        else:
            result = 'Draw'
    
    outstr = "Case #" + str(loop+1) + ": " + result
    #print outstr
    outf.write(outstr + "\n")

outf.close()
