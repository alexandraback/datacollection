import math

def solve():
    X, R, C = map(int, input().split())
    if X >= 7:
        return True
    if (R*C) % X != 0:
        return True
    if math.floor((X+1) / 2) > min(R, C):
        return True
    if (R == 2 or C == 2) and X >= 4 and X % 2 == 0:
        return True

tcnum = int(input())

for tc in range(1, tcnum+1):
    print("Case #{}: {}".format(tc, "RICHARD" if solve() else "GABRIEL"))