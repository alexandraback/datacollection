RICHARD = 0
GABRIEL = 1

for T in range(int(input())):
    X, R, C = map(int, input().split())
    if X == 1:
        result = GABRIEL
    elif X == 2:
        if (R*C) % 2 == 0:
            result = GABRIEL
        else:
            result = RICHARD
    elif X == 3:
        if R*C == 3 or (R*C) % 3 != 0:
            result = RICHARD
        else:
            result = GABRIEL
    elif X == 4:
        if R*C == 4 or R*C == 8 or (R*C) % 4 != 0:
            result = RICHARD
        else:
            result = GABRIEL
    print ("Case #%d: %s" % (T+1, "RICHARD" if result == RICHARD else "GABRIEL"))