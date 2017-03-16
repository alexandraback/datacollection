import sys

def solve(X, R, C):
    if X == 1:
        return 'GABRIEL'
    if X == 2:
        if (R * C) % 2 == 0:
            return 'GABRIEL'
        return 'RICHARD'
    if X == 3:
        if (R * C) % 3 == 0:
            if min(R, C) > 1:
                return 'GABRIEL'
        return 'RICHARD'
    if X == 4:
        if (R * C) % 4 == 0:
            if min(R, C) <= 2:
                return 'RICHARD'
            return 'GABRIEL'
        return 'RICHARD'

    return 'HUH'

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            X, R, C = [int(x) for x in inp.readline().strip().split()]
            out.write('Case #%d: %s\n' % (t + 1, solve(X, R, C)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
