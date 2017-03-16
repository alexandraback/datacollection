import sys

def numberNeeded(K, C):
    return (K+C-1) / C   # division with up-rounding.

def buildNumber(base, digits):
    # Treats the given digits as a number in the given base.
    # Returns the value of this number plus 1.
    result = 0
    for digit in digits:
        result = result * base + digit
    return result + 1

def solveCase(K, C):
    if C > K:
        C = K
    positions = []
    for start in range(0, K-C, C):
        positions.append(buildNumber(K, range(start, start+C)))
    positions.append(buildNumber(K, range(K-C, K)))
    assert len(positions) == numberNeeded(K, C)
    return positions

def _doMain():
    inp = sys.stdin
    ncases = int(inp.readline())
    for cs in range(1, ncases+1):
        K, C, S = [int(part) for part in inp.readline().split()]
        assert 1 <= S <= K
        if S < numberNeeded(K, C):
            print "Case #%d: IMPOSSIBLE" % cs
        else:
            clearTiles = solveCase(K, C)
            print "Case #%d: %s" % (cs, ' '.join(str(pos).replace("L", "") for pos in clearTiles))

if __name__ == '__main__':
    _doMain()
