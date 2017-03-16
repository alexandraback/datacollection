# Google Code Jam 2015 Qualifying D.
# These prevent tiling:
# X 7 and up (can have holes)
# X doesn't divide rectangle size
# X exceeds longer rectangle dimension (1xX won't fit)
# Widest piece exceeds shorter dimension
# Looks like tetromino T and Z prevent tiling 2xN
# Looks like pentomino W prevents 3xN and all can do 4xN.  They all do 4x5.
# Looks like some hexonimos prevent 3xN, probably all can do 4xN N > 3
import sys

# True if X-ominoes can tile R x C rectangle including hardest piece.
def canTile(x, r, c):
    if x >= 7:
        return False            # Can have holes
    if r * c % x != 0:
        return False            # Wrong number of cells
    if x > max(r, c):
        return False            # 1xX won't fit
    if x <= 2:
        return True             # Monominos and dominos are easy
    if x == 6 and min(r, c) > 3:
        return True             # Apparently hexonimos can do 6x4
    if min(r, c) < x - 1:
        return False            # General rule for min width
    return True

def doCase(file):
    (x, r, c) = map(int, file.readline().split())
    return "GABRIEL" if canTile(x, r, c) else "RICHARD"

def run():
    file = open(sys.argv[1])
    numCases = int(file.readline())
    for case in range(1, numCases+1):
        answer = doCase(file)
        print 'Case #{0}: {1}'.format(case, answer)
run()
