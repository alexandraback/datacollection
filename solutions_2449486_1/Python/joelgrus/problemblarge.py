infile = "B-large.in"
outfile = "B-large.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")#

from collections import defaultdict

T = int(lines[0])
lines = lines[1:]

for loop in range(T):
    N,M = [int(x) for x in lines[0].split()]
    lines = lines[1:]
    board = [ [int(c) for c in line.split()]
              for line in lines[:N] ]
    #print N,M
    #print board
    lines = lines[N:]

    col_maxes = [max([board[i][j] for i in range(N)])
                 for j in range(M)]
    row_maxes = [max([board[i][j] for j in range(M)])
                 for i in range(N)]

    # need every cell to equal either its rowmax or its colmax
    if all([board[i][j] in [col_maxes[j],row_maxes[i]]
            for i in range(N)
            for j in range(M)]):
        result = "YES"
    else:
        result = "NO"
        
    outstr = "Case #" + str(loop+1) + ": " + result
    #print outstr
    outf.write(outstr + "\n")

outf.close()
