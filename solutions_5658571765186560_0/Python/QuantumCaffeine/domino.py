# Solution to "Ominous Domino" for Google Code Jam 2015
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

def solve(x, r, c):
    if r > c:
        r, c = c, r
    if (r*c)%x != 0:      #Can't fit whole number of pieces
        return "RICHARD"
    if r < x and c < x:   #Can't fit straight rod in either direction
        return "RICHARD"
    if r >= x and c >= x: #Can fit anything
        return "GABRIEL"
    if 2*r + 1 <= x:      #Can make an r+1 cross
        return "RICHARD"
    #Now we're down to r < x, c >= x and 2*r + 1 > x
    #So (x-1)/2 < r < x
    if r == 1:
        if x <= 2:
            return "GABRIEL"
        else:
            return "RICHARD"
    if 2*r == x: #Can make an r*(r+1) cross
        return "RICHARD"
    if 2*r - 1 == x: #Can make an r*r cross
        return "GABRIEL"
    if 2*r - 1 > x:
        return "GABRIEL"


def cases():
    with open(sys.argv[1], 'r') as infile:
        numCases = int(infile.readline())
        for _ in range(numCases):
            yield [int(x) for x in infile.readline().split()]

def main():
    with open(sys.argv[2], 'w') as outfile:
        for caseNo, case in enumerate(cases()):
            outfile.write("Case #%d: %s\n"%(caseNo + 1, str(solve(*case))))

if __name__ == "__main__":
    main()
