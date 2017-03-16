import sys

def canFill(x, r, c):
    if x>=7:
        return False
    if r*c % x != 0:
        return False
    if r<x and c<x:
        return False
    if min(r,c) < (x+1)/2:
        return False
    if x<=3:
        return True
    if x==4:
        return r>2 and c>2
    if x==5:
        return {r,c} != {3,5}
    if x==6:
        return r>3 and c>3

    raise Exception("How did I get here?!")


if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for i in range(ncases):
        line = sys.stdin.readline()
        x, r, c = [int(part) for part in line.split()]
        winner = "GABRIEL" if canFill(x, r, c) else "RICHARD"
        print "Case #%d: %s" % (i+1, winner)

