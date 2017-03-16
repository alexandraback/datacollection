#!/usr/bin/python3

T = int(input())

for run in range(1, T + 1):
    X, R, C = map(int, input().split(' '))
    if R > C:
        R, C = C, R

    # GABRIEL IF CAN NOT CHOOSE TILE
    # RICHARD IF CAN CHOOSE TILE

    # here assume i x j where i <= j
    # 1: always GABRIEL
    # 2: RICHARD iff 1x1 or odd number
    # 3: if 1xn -> RICHARD
    #    if 2x2 -> RICHARD
    #    if 2x3 -> GABRIEL
    #    if 2x4 -> 8 % 3 = 2 -> RICHARD
    #    if 3x3 -> GABRIEL
    #    if 3x4 -> GABRIEL
    #    if 4x4 -> 16 % 3 = 1 -> RICHARD
    # 4: if 1xn -> RICHARD (2x2)
    #    if 2x2 -> RICHARD (4x1)
    #    if 2x3 -> RICHARD (4x1)
    #    if 2x4 -> RICHARD (o o o)
    #                     (  o  )
    #    if 3x3 -> RICHARD (9 % 4 = 1)
    #    if 3x4 -> GABRIEL
    #    if 4x4 -> GABRIEL

    win = -1
    if X is 1:
        win = 0
    elif X is 2:
        if (R * C) % 2 is 1:
            win = 1
        else:
            win = 0
    elif X is 3:
        if R is 1:
            win = 1
        elif R is 2:
            if C is 2:
                win = 1
            elif C is 3: 
                win = 0
        elif R is 3:
            win = 0
        elif R is 4:
            win = 1
    elif X is 4:
        if R >= 3 and C is 4:
            win = 0
        else:
            win = 1

    if win is 0:
        print("Case #%i: %s" % (run, 'GABRIEL'))
    else:
        print("Case #%i: %s" % (run, 'RICHARD'))

