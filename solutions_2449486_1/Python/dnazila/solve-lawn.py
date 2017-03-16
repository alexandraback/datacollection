import sys

fname = sys.argv[1]

f = open(fname, "rt")

T = int(f.readline())

def handle_case(f, caseno):
    line = f.readline()
    vals = line.split()
    N = int(vals[0])
    M = int(vals[1])
    mat = [[0 for j in range(M)] for i in range(N)]
    for lineno in range(N):
        line = f.readline() 
        vals = line.split()
        mat[lineno] = [int(s) for s in vals]

    rows = [max(mat[i]) for i in range(N)]

    cols = [max([mat[i][j] for i in range(N)]) for j in range(M)]


    for i in range(N):
        for j in range(M):
            if mat[i][j] < rows[i] and mat[i][j] < cols[j]:
                print "Case #%d: NO" %caseno
                return
    print "Case #%d: YES"%caseno





    
    

        

for case in range(T):
    handle_case(f, case+1)
        

    
