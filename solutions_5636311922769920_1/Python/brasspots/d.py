#!/usr/bin/python


def solution(K,C,S):
    """
    K - length of original sequence
    C - number of iterations C =  means the final sequence is the original sequance
    S - the number of tiles in the final sequence that can be checked
    Output - List of tiles to check or empty list if its not possible
    Task - which tiles to check to determine is the original sequence was all L or if it had >= 1 G
    """
    #assertion - each tile in the final sequence encodes an AND function of some combination of C tiles of the
    # original sequence. that is the tile in the final sequence is L if all C tiles it encodes are L in the original
    # sequence.
    # This means it can be solved if S >= K/C
    if C > K: C = K
    if S >= float(K)/C:
        # split into tuples, the tiles encoded in the checked tile
        tiles_encoded = []
        tiles = []
        _k = 1
        for i in range(K/C):
            tiles_encoded.append(tuple([_k + j for j in range(C)]))
            _k += C
        if _k <= K:
            tiles_encoded.append(tuple([K - j for j in range(C-1,-1,-1)]))
        for indexs in tiles_encoded:
            indexs = list(indexs)[::-1]
            tot = 0
            i = 0
            for ind in indexs:
                tot += K**i * (ind-1)
                i += 1
            tiles.append(tot +1)
        return tiles
        
    else:
        return []

results = []
with open('dl.in') as f:
    T = int(f.readline())
    print 'There are {} testcases'.format(T)
    for TC in range(1, T+1):
        K, C, S = [int(x) for x in f.readline().strip().split(' ')]
        outline = 'Case #{}:'.format(TC)
        sol = solution(K,C,S)
        if not sol:
            outline += ' IMPOSSIBLE'
        else:
            for x in sol:
                outline += ' {}'.format(x)
        results.append(outline)
with open('dl.out', 'w') as f:
    for r in results:
        f.write(r+'\n')





