#!/usr/bin/python3
#
# @author Andres Ayala (killerrex@gmail.com)
#


def linecheck(line):
    """
    X => X Won
    O => O Won
    K => Keep playing
    D => Draw
    """
    prev = None
    red = set(line)
    if red.issubset("TX"):
        return "X"
    if red.issubset("TO"):
        return "O"
    if "." in red:
        return "K"
    else:
        return "D"
        
    

def status(grid):
    res = "D"
    for i in range(4):
        # Horizontal check
        l = linecheck(grid[i])
        if l in "XO":
            return l
        elif l == "K":
            res = "K"
        
        # Tricky: columns
        col = [ grid[j][i] for j in range(4) ]
        l = linecheck(col)
        if l in "XO":
            return l
        elif l == "K":
            res = "K"
    # Finally both diagonals
    diag = [grid[i][i] for i in range(4)]
    l = linecheck(diag)
    if l in "XO":
        return l
    elif l == "K":
        res = "K"
    diag = [grid[3-i][i] for i in range(4)]
    l = linecheck(diag)
    if l in "XO":
        return l
    elif l == "K":
        res = "K"
    return res

TABLE = {
    "X": "X won",
    "O": "O won",
    "D": "Draw",
    "K": "Game has not completed"
}

def solve(fd):
    T = int(fd.readline().strip())
    for c in range(T):
        grid = [ fd.readline().strip() for i in range(4) ]
        res = status(grid)
        print("Case #" + str(c+1) + ": " + TABLE[res])
        fd.readline()
            
if __name__ == "__main__":
    import sys
    
    fd = open(sys.argv[1], "r")
    solve(fd)
    fd.close()

            
