#!/usr/bin/env python3 

def solve_case(K, C, S):
    if (K + C - 1) // C > S:
        return "IMPOSSIBLE"
    probes = []
    tiles = list(range(K))
    if K % C != 0:
        tiles.extend([0] * (C - K % C))
    for block_start in range(0, len(tiles), C):
        block = tiles[block_start:block_start+C]
        probe = 0
        for t in block:
            probe = K * probe + t
        probes.append(probe+1) 
    return ' '.join(map(str, probes))

def main():
    T = int(input())
    for ci in range(1, T+1):
        K, C, S = map(int, input().split())
        print("Case #{}: {}".format(ci, solve_case(K, C, S)))

main()
