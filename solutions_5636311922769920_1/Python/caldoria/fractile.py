# Eventually switching to python because I didn't manage to get the exponentiation of large numbers right in C++.

import sys

def abs_coordinate (K, coords):
    sum = 0
    power = 0
    for c in coords:
        sum += c * K**power
        power += 1
    return sum

T = int(raw_input())

for i in range(T):
    line = raw_input()
    K, C, S = map(int, line.split())

    possible = S*C >= K

    tiles = []

    if possible:
        coords = []
        for k in range(K):
            coords.append(k)
            if len(coords) == C or k == K-1:
                tile = abs_coordinate(K, coords)+1
                tiles.append(tile)
                coords = []

    sys.stdout.write("Case #{}:".format(i+1))
    if possible:
        for tile in tiles:
            sys.stdout.write(" {}".format(tile))
    else:
        sys.stdout.write(" IMPOSSIBLE")
    sys.stdout.write("\n")
    sys.stdout.flush()
