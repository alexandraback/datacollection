import sys

def canFill(x, r, c):
    if x>=7:
        return False    # Richard picks a nasty shape with a hole
    if r*c % x != 0:
        return False    # Obvious
    if r<x and c<x:
        return False    # Richard picks the 1*x shape
    if min(r,c) < (x+1)/2:
        return False    # Richard picks a shape whose size is at least (x+1)/2 in each dimension
    if x<=3:
        return True
        # r,c>1, otherwise the previous 'if' would fail.
        # r or c is a multiple of 3.
        # So Gabriel can take Richard's shape twice and build a 2*3 blocks (like in your sample, case 4),
        # and fill the board with such 2*3 blocks (plus, maybe, a 1*3 piece).
    if x==4:
        return r>2 and c>2
        # If it's a long 2*x stripe, Richard can pick the Z shape, thus we're stuck with an odd
        # number of cells on each side.
        # Otherwise, the dimensions are at least 3*4, and it can be easily seen that Gabriel can fill
        # a 3*4 area given whatever Richard uses, and fill the margins with 1*4 or 2*2 shapes.
    if x==5:
        return {r,c} != {3,5}
        # One of the dimensions is a multiple of 5, and the other one is at least 3.
        # I manually managed to fill a 3*5 area using any pentamino that Richard may choose, EXCEPT one
        # (the "staircase" shape). But a 3*10 area can be filled with it as well.
    if x==6:
        return r>3 and c>3
        # If it's a long 3*x stripe, Richard can use the cross, thus we're stuck on each side with a
        # number of cells that doesn't divide by 3.
        # Otherwise, the dimensions are at least 6*4, and it's quite easy to see that a 4*6 area can be
        # filled whatever Richard's shape is, and the margins can be filled with 3*2 or 1*6 shapes.
        # Thanks wikipedia for the picture of "Hexomino".


if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for i in range(ncases):
        line = sys.stdin.readline()
        x, r, c = [int(part) for part in line.split()]
        winner = "GABRIEL" if canFill(x, r, c) else "RICHARD"
        print "Case #%d: %s" % (i+1, winner)

