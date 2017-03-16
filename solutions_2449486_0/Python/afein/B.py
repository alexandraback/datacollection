from sys import stdin

def has_greater(grid, x, y, N, M):
    res = 0
    for i in range(0, N):
        if grid[i][y] > grid[x][y]:
            res += 1
            break
    for j in range(0, M):
        if grid[x][j] > grid[x][y]:
            res += 1
            break
    if res == 2:
        return True
    return False

def main():
    for case in range(1, int(stdin.readline()) + 1):
        outp = "YES"
        N, M = map(int, stdin.readline().split())
        grid = [ stdin.readline().split() for i in range(0, N)]

        for i in range(0, N):
            for j in range(0, M):
                if has_greater(grid, i, j, N, M):
                    outp = "NO"
                    break

        print "Case #" + str(case) + ": " + outp

if __name__=="__main__":
    main()
