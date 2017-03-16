#!/usr/bin/python3


def check_tile(grid, N, M, r, c):
    tile = grid[r][c]
    # At least one of both must be true or the set is imposible
    return all(grid[r][j]<=tile for j in range(M)) or all(grid[i][c]<=tile for i in range(N))

def check(grid, N, M):
    
    # Search For tiles where is not the higher in one direction
    # Row Compatibility
    for i in range(N):
        for j in range(M):
            if not check_tile(grid, N, M, i,j):
                return "NO"
    return "YES"


def solve(fd):
    
    T = int(fd.readline().strip())

    for c in range(T):
        N, M = [ int(a) for a in fd.readline().strip().split() ]
        grid = [ [ int(a) for a in fd.readline().strip().split() ] for i in range(N) ]
        print("Case #" + str(c+1) + ": " + check(grid, N, M))


                    
if __name__ == "__main__":
    import sys
    
    fd = open(sys.argv[1], "r")
    solve(fd)
    fd.close()

                
        
