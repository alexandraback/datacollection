#!/usr/bin/python

def solve(X, R, C):
    if R * C < X:
        return "RICHARD"
    if (R * C) % X != 0:
        return "RICHARD"
    if X <= 2:
        return "GABRIEL"
    if min(R, C) <= X - 2:
        return "RICHARD"
    return "GABRIEL"

def main():
    t = int(raw_input())
    for i in range(1, t + 1):
        X, R, C = [int(s) for s in raw_input().split()]
        print("Case #{}: {}".format(i, solve(X, R, C)))

if __name__ == "__main__":
    main()
