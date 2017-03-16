def solve_lawn(lawn, M, N):
    max_rows = []
    max_cols = []
    for r in lawn: 
        max_rows.append(max(r))
    for c in range(0,N):
        max_val = 0
        for r in range(0,M):
            if lawn[r][c] > max_val:
                max_val = lawn[r][c]
        max_cols.append(max_val)

    for r in range(0, M):
        for c in range(0,N): 
            if lawn[r][c] < max_rows[r] and lawn[r][c] < max_cols[c]:
                return False
    return True
    

if __name__ == "__main__":
    with open("input_large") as f:
        lines = f.readlines()

    N = int(lines[0])
    l = 1
    for case in range(0, N):
        (M, N) = lines[l].strip().split()
        M = int(M)
        N = int(N)
        garden = []
        for r in range(0,M):
            #readline
            garden.append([int(i) for i in lines[l+r+1].strip().split()])
        print "Case #" + str(case + 1) + ": " + ( "YES" if solve_lawn(garden, M, N) else "NO")
        l += M + 1
        

