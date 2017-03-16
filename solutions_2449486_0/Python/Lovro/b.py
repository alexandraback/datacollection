def solve(R, C, mat):
    rows = [0] * R
    cols = [0] * C
    for i in range(R):
        for j in range(C):
            rows[i] = max(rows[i], mat[i][j])
            cols[j] = max(cols[j], mat[i][j])
    
    for i in range(R):
        for j in range(C):
            if min(rows[i], cols[j]) != mat[i][j]:
                return 'NO'
            
    return 'YES'

ncases = int(input())
for i in range(1, ncases+1):
    R, C = tuple(int(t) for t in input().split())
    mat = []
    for _ in range(R):
        mat.append([int(t) for t in input().split()])
    print('Case #{}: {}'.format(i, solve(R, C, mat)))
