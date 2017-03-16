import math

def solve(grid):
    grid.sort()
    count = (len(grid)+1)/2
    ret = []
    while grid:
        n1 = grid.pop(0)
        if(grid==[] or n1!=grid[0]):
            ret=ret+[n1]
        else:
            grid.pop(0)
    return ' '.join(map(str,ret))

if __name__ == "__main__":
    testcases = input()
    for caseNr in xrange(1, testcases+1):
        rows = input()
        grid = []
        for line in xrange(0, rows*2-1):
            n = raw_input()
            grid += map(int, n.split(" "))
        print("Case #%i: %s" % (caseNr, solve(grid)))
