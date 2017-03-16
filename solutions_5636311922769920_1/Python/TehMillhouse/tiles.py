#! /usr/bin/env python3

for it in range(1, int(input()) + 1):
    K, C, S = map(int, input().split())
    print('Case #' + str(it) + ':', end='')
    if S * C < K:
        print(' IMPOSSIBLE')
        continue
    # every grad student can implicitly check C tiles
    for tile in range(1, K+1, C):
        print(' ', end='')
        prefix = K * (tile - 1) * pow(K, C)
        for depth in range(C):
            prefix *= K
            prefix += min(K - 1, tile + depth)
        print(prefix + 1, end='')
    print()

