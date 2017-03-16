import fileinput,sys
import math

print_indicator = 0

def myprint(*arg):
    if print_indicator != 0:
        print print_indicator
        print arg

lines = []

for line in fileinput.input():
    lines.append(line)

n= int(lines[0])


def knapslow(row,N, E,R):
    table = [[0 for col in range(E+1)] for foo in range(N+2)]
    myprint ("row", row)
    myprint ("N,E,R", N,E,R)
    for i in xrange(1,N+1):
        for j in xrange(R,E+1):
            for k in xrange(0,j+1):
                foo = min(j-k+R,E)
                table[i][foo] = max(table[i][foo], table[i-1][j] + row[i-1]*k)
    myprint("filled in table", table)
    return table[N][R]

myprint("lines", lines)
case = 0
line_no =1      
for j in xrange(1,n+1):
    case +=1
    print "Case #%d:" % (case),
    nbym = (lines[line_no]).partition(" ")
    myprint("n e r", nbym)
    line_no +=1
    E = int(nbym[0])
    ugh = nbym[2].partition(" ")
    R = int(ugh[0])
    N = int(ugh[2])
    if (R > E):
        R = E
    myprint("line_no", line_no)
    current_line = lines[line_no]
    myprint("current_line", current_line)
    line_no+=1
    row = []
    for k in xrange(0,N):
        cl_split = current_line.partition(" ")
        row.append(int(cl_split[0]))
        current_line = cl_split[2]
    val =  knapslow(row,N,E,R)
    myprint("Answer", val)
    print val
