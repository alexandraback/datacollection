import sys
import math

inName = sys.argv[1]
outName = inName[:inName.index('.')] + '.out'

fin = open(inName)
fout = open(outName, 'w')

cases = int(fin.readline())

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)

for case in xrange(cases):
    [R, C, W] = map(int, fin.readline().strip().split(' '))

    guesses = 0
    grid = [0 for i in range(C)]
    print grid

    for i in range(W-1, C, W):
        grid[i] = 1
        guesses += 1
    print grid
    guesses += W - 1

    if C % W != 0:
        guesses += 1

    guesses += (R - 1) * int(math.floor(C / W))

    # print R, C, W

    pp(case, guesses)

fout.close()
