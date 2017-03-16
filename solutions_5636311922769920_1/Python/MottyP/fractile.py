# We can treat a position in the art piece as a the list of digits representing it in base K (counted from 0). For example:
# [0,0,0,0,0,...] is the first tile.
# [K-1, K-1, K-1, ...] is the last tile.
# [0, anything..] is anywhere in the first 1/K of the piece, that is, in the first sequence of K^(C-1) tiles.
# [2, anything..] is anywhere in the third 1/K of the piece, that is, in the third sequence of K^(C-1) tiles.
# [anything.., 4] is a position that is equal 4 modulo K^(C-1).
#
# Now, let value(pattern, K, [a,b,c,d...]) -> {G,L}  be the tile at the given position of the given art piece.
# (Note that this function can deduce C by the length of the "position" parameter).
# For complexity 1,   value(pattern, K, [a]) = pattern[a]
# In general,         value(pattern, K, [a,b,c,d,...]) = Gold if pattern[a] is Gold, else value(pattern, K, [b,c,d,...].
# Why? if pattern[a] is gold, then the a'th part of the next "generation" is full of gold tiles.
# if pattern[a] is lead, then the a'th part of the next "generation" is a copy of the pattern, and we have yet to examine the
# position [b,c,d,...] relative to this copy.
# 
# The solution is to construct positions whose list-representations covers all the numbers 0..K-1;
# this way, if tile j of the pattern is golden, then value(pattern, K, [..., j, ...]) will evaluate to Gold.
# For example, for K=10, C=3, the solution contains 4 tiles at positions [0,1,2], [3,4,5], [6,7,8], [7,8,9].
# (It seems that your example output was generated this way..)
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
