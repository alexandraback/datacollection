import math

def solve():
    X, R, C = map(int, input().split())
    if X > R*C:
        return True
    if (R*C) % X != 0:
        return True
    if X >= 7:
        return True
    if X == 6:
        if R <= 3 or C <= 3:
            return True
        else:
            return False
    if X == 5:
        if R > 3 and C > 3:
            return False
        elif (R == 3 and C == 5) or (R == 5 and C == 3):
            return True
        elif R <= 2 or C <= 2:
            return True
        else:
            return False
    if X == 4:
        if R > 2 and C > 2:
            return False
        else:
            return True
    if X == 3:
        return R == 1 or C == 1
    return False



tcnum = int(input())

for tc in range(1, tcnum+1):
    print("Case #{}: {}".format(tc, "RICHARD" if solve() else "GABRIEL"))