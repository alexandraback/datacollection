import sys

fp = open(sys.argv[1])
def readline():
    return fp.readline().strip()

def solve(k, c, s):
    # if c >= k then one tile suffices: the a1 or a2 or ... or ak
    # if c < k then you need ceil(k/c): a1 or ... or ac, a{c+1} or ... or
    #   a{2c}, etc.
    # degenerate case when c == 1: ceil(k) = k
    assert s >= 1
    def select_tile(coords):
        assert len(coords) == c
        n = 0
        for x in coords:
            n *= k
            n += x
        n += 1
        return n
    if c >= k:
        return str(select_tile(range(k) + [0] * (c - k)))
    else:
        if s * c < k:
            return 'IMPOSSIBLE'
        coords = range(k)
        tiles = []
        while coords:
            subcoords = coords[:c]
            del coords[:c]
            subcoords += [0] * (c - len(subcoords))
            assert len(subcoords) == c
            tiles.append(select_tile(subcoords))
        return ' '.join(str(t) for t in tiles)

if __name__ == '__main__':
    num_cases = int(readline())
    for i in xrange(num_cases):
        k, c, s = [int(x) for x in readline().split()]
        print "Case #%d: %s" % (i + 1, solve(k, c, s))
