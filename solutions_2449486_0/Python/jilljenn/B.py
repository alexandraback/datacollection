def r(M, N, grid):
    for i in range(M):
        for j in range(N):
            if any(grid[i][k] > grid[i][j] for k in range(N)) and any(grid[k][j] > grid[i][j] for k in range(M)):
                return 'NO'
    return 'YES'

if __name__ == '__main__':
    T = int(raw_input())
    for i in range(T):
        M, N = map(int, raw_input().split())
        grid = []
        for _ in range(M):
            grid.append(map(int, raw_input().split()))
        print 'Case #%d: %s' % (i + 1, r(M, N, grid))