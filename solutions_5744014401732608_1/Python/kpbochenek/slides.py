#!/bin/python3

T = int(input())

POSSIBLE = "POSSIBLE"
IMPOSSIBLE = "IMPOSSIBLE"

POWS = list(reversed([(i, pow(2, i-2)) for i in range(55)]))


for t in range(T):

    B, M = map(int, input().split())

    MAX_MILLIS = pow(2, B-2)

    if M <= MAX_MILLIS:
        MATRIX = [['0']*B for i in range(B)]
        for i in range(B):
            for j in range(B):
                if i < j:
                    MATRIX[i][j] = '1'

        DIFF_M = MAX_MILLIS - M
        XXX = B - 1
        while XXX > 0:
            val = pow(2, XXX-1)
            if 0 < DIFF_M and val < DIFF_M:
                DIFF_M = DIFF_M - val
                MATRIX[XXX][B-1] = '0'
            XXX -= 1
        if DIFF_M == 1:
            MATRIX[0][B-1] = '0'

        print("Case #" + str(t+1) + ": " + POSSIBLE)
        for i in range(B):
            print("".join(MATRIX[i]))

    else:
        print("Case #" + str(t+1) + ": " + IMPOSSIBLE)
