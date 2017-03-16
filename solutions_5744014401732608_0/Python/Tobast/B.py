
def solve():
    nbBuild, target = [int(x) for x in input().strip().split(' ') ]
    grid = [ [0]*(i+1) + [1] * (nbBuild-i-1) for i in range(nbBuild)]
    grid[0] = [0] * nbBuild
    grid[-1] = [0] * nbBuild

    target -= 1
    grid[0][-1] = 1
    for pos in range(nbBuild-2, 0, -1):
        if target % 2 == 1:
            grid[0][pos] = 1
        target //= 2

#    if target > 0:
#        grid[0][-1] = 1
#        target -= 1
    
    if target > 0:
        return "IMPOSSIBLE"
    out = "POSSIBLE\n"
    for line in grid:
        for val in line:
            out += str(val)
        out += '\n'
    return out[:-1]

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1,solve()))
