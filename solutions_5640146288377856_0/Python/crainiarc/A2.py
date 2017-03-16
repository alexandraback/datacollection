import sys


def battle(R, C, W):
    res = C / W * R
    res += W-1 if C%W == 0 else W
    return res


if __name__ == '__main__':
    TC = int(raw_input())
    for i in range(1, TC+1):
        R, C, W = [int(j) for j in raw_input().split()]
        print("Case #" + str(i) + ": " + str(battle(R, C, W)))
