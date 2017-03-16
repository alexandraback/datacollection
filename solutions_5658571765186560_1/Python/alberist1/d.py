#!/usr/bin/python3
def solve():
    R, G = "RICHARD", "GABRIEL"
    x, r, c = map(int, input().split())
    if (r*c) % x != 0:
        return R
    if x == 1:
        return G
    if x == 2:
        return G
    if min(r, c) == 1:
        return R
    if x == 3:
        return G
    if min(r, c) == 2:
        return R
    if x == 4:
        return G
    if min(r, c) == 3:
        return R
    if x == 5:
        return G
    if max(r, c) < 6:
        return R
    if x == 6:
        return G
    if x >= 7:
        return R

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print('Case #%d:' % (t+1), solve())
