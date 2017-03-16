#!/usr/bin/python3.4

T = int(input())

for case in range(1, T + 1):
    gab = "Case #%d: GABRIEL" % case
    ric = "Case #%d: RICHARD" % case
    X, R, C = map(int, input().split())
    if (R > C): 
        R, C = C, R
    if (X == 1):
        print(gab)
    if (X == 2):
        if ((R*C % 2) == 1):
            print(ric)
        else:
            print(gab)
    if (X == 3):
        if (R < 2):
            print(ric)
        elif ((R*C % 3) == 0):
            print(gab)
        else:
            print(ric)
    if (X == 4):
        if (R < 3):
            print(ric)
        elif (C == 3):
            print(ric)
        else:
            print(gab)
    if (X == 5):
        if (R < 3):
            print(ric)
        elif ((R == 3) and (C == 5)):
            print(ric)
        elif ((R*C % 5) == 0):
            print(gab)
        else:
            print(ric)
    if (X == 6):
        if (R < 3):
            print(ric)
        elif ((R*C % 6) != 0):
            print(ric)
        elif (R == 3):
            print(ric)
        else:
            print(gab)
    if (X >= 7):
        print(ric)
