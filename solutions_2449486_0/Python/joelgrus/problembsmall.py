infile = "B-small-attempt0.in"
outfile = "B-small.out"
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
    print N,M
    print board
    lines = lines[N:]

    one_rows = {i for i in range(N)
                if all([board[i][j] == 1 for j in range(M)])}
    one_cols = {j for j in range(M)
                if all([board[i][j] == 1 for i in range(N)])}

    # need every one to be in a one row or one col
    result = "YES"
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                if i not in one_rows and j not in one_cols:
                    result = "NO"
                    break
        
    outstr = "Case #" + str(loop+1) + ": " + result
    #print outstr
    outf.write(outstr + "\n")

outf.close()
