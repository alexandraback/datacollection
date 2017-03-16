
import sys
import math

orig_stdin = sys.stdin
#fin = open('example.in', 'r')
fin = open('B-small-attempt1.in', 'r')
#fin = open('B-large.in', 'r')
sys.stdin = fin

orig_stdout = sys.stdout
foutname = fin.name.replace(".in",".out.txt")
fout = open(foutname, 'w')
sys.stdout = fout


T = int(input())  #number of cases

for case in range(1,T+1):
    
    ans = 0

    N = int(input())

    grid = [ [int(x) for x in input().split()] for i in range(2*N-1) ]
    #print(grid, file = sys.stderr)

    allgrid = [x for row in grid for x in row]

    newrow = []
    for n in allgrid:
        if allgrid.count(n)%2 == 1 and n not in newrow:
            newrow.append(n)

    newrow.sort()

    #print(newrow, file = sys.stderr)
    newrow2 = [str(a) for a in newrow]

    ans = ' '.join(newrow2)
    
    print("Case #%d:" % case, ans)
    print("Case #%d:" % case, ans, file = sys.stderr)
    

sys.stdout = orig_stdout
sys.stdin = orig_stdin
fin.close()
fout.close()