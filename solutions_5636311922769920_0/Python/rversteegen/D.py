T = int(raw_input())
for testcase in range(T):
    K,C,S = [int(x) for x in raw_input().split()]
    if S*C < K:
        print "Case #%d: IMPOSSIBLE" % (testcase+1)
    else:
        tiles = []
        tile = 0
        bits = range(K)
        if K%C:
            bits += [0]*(C-K%C)
        def get(bits):
            tile = 0
            for bit in bits:
                tile = tile*K + bit
            return tile
        while bits:
            tiles.append(str(get(bits[:C])+1))
            bits = bits[C:]
        print "Case #%d:" % (testcase+1), ' '.join(tiles)
    
