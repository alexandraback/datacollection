#!/usr/bin/env python3


def testcase():
    names = ['GABRIEL', 'RICHARD']
    X, R, C = map(int, input().split())
    if R*C % X != 0:
        return names[1]
    if X < 3:
        return names[0]
    if X == 3:
        return names[R*C < 6]
    if X == 4:
        return names[R*C < 12]

    return C


def main():
    T = int(input())
    for t in range(T):
        print("Case #{}: {}".format(t+1, testcase()))


if __name__ == '__main__':
    main()
