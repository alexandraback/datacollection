#! /usr/bin/env python3

for it in range(1, int(input()) + 1):
    stack = input()
    flips = 0
    run = 0
    for p in stack:
        if p == '-' and run == 0:
            flips += 2
        if p == '-':
            run += 1
        else:
            run = 0
    if stack[0] == '-':
        # we need one fewer flip
        flips -= 1
    print('Case #' + str(it) + ': ' + str(flips))

