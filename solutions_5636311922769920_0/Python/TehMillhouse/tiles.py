#! /usr/bin/env python3

for it in range(1, int(input()) + 1):
    K, C, S = map(int, input().split())
    print('Case #' + str(it) + ': ', end='')
    if S < K:
        print('IMPOSSIBLE')
        continue
    # this only works if S = K, but we have that garantee
    print(' '.join((str(i) for i in range(1, S + 1))))
