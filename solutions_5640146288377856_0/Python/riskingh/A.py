import sys
from math import *

def solve(fin):
    R, C, W = map(int, fin.readline().split())
    ans = (R - 1) * (C // W)

    if C == W:
        ans = W
    else:
        ans += (C // W) + (W - 1)
        if C % W != 0:
            ans += 1

    print(ans)


def main():
    fin = open("input.txt", "r")
    
    T = int(fin.readline())
    for _T in range(1, T + 1):
        print("Case #" + str(_T) + ": ", end = "")
        solve(fin)

    fin.close()

main()