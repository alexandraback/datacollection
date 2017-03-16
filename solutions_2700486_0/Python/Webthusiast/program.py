# from itertools import *
# from math import *
from sys import stdin


def D(d):
    return 4 * d + 1


def DC(d):
    # sum (4i+1 for 0<=i<d+1)
    # 4 * sum (i for 0<=i<d+1) + d+1
    # 4 * d * (d+1) / 2 + d+1
    return 2 * d * (d + 1) + d + 1


def P(Z, N):
    if Z == 0: return 1.0
    elif Z > N: return 0.0
    else:
        return 0.5 * (P(Z, N-1) + P(Z-1, N-1))


def case(N, X, Y):
    # N: nr of falling diamonds
    # X: X coordinate of location
    # Y: Y coordinate of location
    # d: distance from O
    # Nd: nr of falling diamonds at distance d
    d = (abs(X) + Y) / 2
    if d == 0:
        return 1.0 if N > 0 else 0.0

    Nd = N - DC(d - 1)
    if Nd <= 0:
        return 0.0
    elif Nd >= D(d):
        return 1.0
    elif X == 0:
        return 0.0
    else:
        Ds = (D(d) - 1) / 2  # max nr of falling diamonds on each side
        if Nd > Ds + Y:
            return 1.0
        elif Nd <= Y:
            return 0.0
        else:
            return P(Y + 1, Nd)


def main():
    input_it = iter(stdin)
    T = int(input_it.next())
    for x in range(1, T + 1):
        N, X, Y = (int(c) for c in input_it.next().split())
        p = case(N, X, Y)
        print 'Case #{}: {}'.format(x, p)


if __name__ == '__main__':
    main()
