import sys

FIRST = "RICHARD"
SECOND = "GABRIEL"

def solve():
    S = input()
    # sys.stderr.write(S + " ")
    X, R, C = map(int, S.split())
    R, C = min(R, C), max(R, C)
    if X == 1:
        return SECOND
    if X >= 7:
        return FIRST
    if R * C % X != 0:
        return FIRST
    if C < X:
        return FIRST
    a = (X - 1) // 2
    b = X - 1 - a
    a += 1
    b += 1
    if a > R or b > C:
        return FIRST
    if X == 4:
        if R < 3:
            return FIRST
        else:
            return SECOND
    return SECOND

for i in range(1, int(input()) + 1):
    res = solve()
    print("Case #", i, ": ", res, sep="")
    # sys.stderr.write(res + "\n")


