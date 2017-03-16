import sys

def solve(r, c, w):
    '''
    Optimal strategy might be:
    1) a. for R > 1 - say "no" until only 1 non-tested row is left
       b. after that - follow R = 1 scenario
       c. to test the row just fire each W cells along it - if all are "miss" no way the ship is there
    2) for R = 1:
       a. fire from the left corner each W cells until remains < 2 * W cells
       b. to find the ship in < 2 * W cells we need W + 1 moves:
            * start firing from the center
            * fire adjacent to the left
            * if our brother says "miss" on any our fire but last we've located the ship - it's to the right
            * he can cheat only on last fire
            * anyway we need to fire all occupied W cells and 1 miss
       c. the formula is: (C div W - 1) + (W + 1)
       d. NOTE: if remaining cells are exactly W we need W moves, not W + 1, to locate the ship
    '''
    nonLastRow = (r - 1) * (c / w)
    lastRow = c / w  + w
    if c % w == 0:
        lastRow -= 1
    return nonLastRow + lastRow

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            R, C, W = [int(x) for x in inp.readline().strip().split()]
            out.write('Case #%d: %s\n' % (t + 1, solve(R, C, W)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
