
def solve(f):
    line1 = next(f)
    h, w = map(int, line1.split())
    lawn = []
    for y in range(h):
        lawn.extend(map(int, next(f).split()))

    def getValue(x, y):
        return lawn[y * w + x]

    highestValueInRows = []
    for y in range(h):
        values = lawn[y*w:(y+1)*w]
        highestValueInRows.append(max(values))

    highestValueInColumns = []
    for x in range(w):
        values = lawn[x::w]
        highestValueInColumns.append(max(values))

    for x in range(w):
        for y in range(h):
            v = getValue(x, y)
            if highestValueInColumns[x] > v and highestValueInRows[y] > v:
                return 'NO'
    return 'YES'

def main(infile, outfile):
    with open(infile, 'r') as f:
        with open(outfile, 'w') as f2:
            cases = int(next(f))
            for i in range(cases):
                solution = solve(f)
                f2.write("Case #{}: {}\n".format(i+1, solution))

import sys
main(*sys.argv[1:3])

