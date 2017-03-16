def solve_case(N,M,pattern):
    pattern_col = []
    for j in xrange(M):
        col = [row[j] for row in pattern]
        pattern_col.append(col)
        
    row_max = []
    for row in pattern:
        row_max.append(max(row))
        
    col_max = []
    for col in pattern_col:
        col_max.append(max(col))
    
    overall_possible = True
    for i in xrange(N): 
        for j in xrange(M):
            if pattern[i][j] < row_max[i] and pattern[i][j] < col_max[j]:
                overall_possible = False
                break
        if not overall_possible:
            break
    if overall_possible:
        result = "YES"
    else:
        result = "NO"
    return result

def solve_cases(fin, fout):
    nCases = int(fin.readline().strip())
    for i in xrange(nCases):
        # get case
        N, M = map(int, fin.readline().strip().split())
        pattern = []
        for _ in xrange(N):
            pattern.append(map(int, fin.readline().strip().split()))
        # solve case
        result = solve_case(N,M,pattern)
        fout.write("Case #%d: %s\n"%(i+1, result))
        print "Case #%d: %s\n"%(i+1, result)

from sys import argv
solve_cases(open(argv[1]), open(argv[1].replace("in", "out"), "w"))
