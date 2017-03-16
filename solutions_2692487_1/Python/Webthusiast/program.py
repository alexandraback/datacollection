# from itertools import *
# from math import *
from sys import stdin


def case(A, N, B):
    # A: Armin's mote's size
    # B: sequence of other motes
    # M: number of added motes
    # N: number of un-eaten motes
    B.sort()
    B.reverse()
    result = N  # the optimum so far
    M = 0  # added motes
    while B:
        b = B.pop()
        N -= 1
        if b < A:
            A += b
            result = min(result, M + N)
        else:
            B.append(b)
            A += A - 1
            N += 1
            M += 1
        if M >= result:
            break
    return result


def main():
    input_it = iter(stdin)
    T = int(input_it.next())
    for x in range(1, T + 1):
        A, N = (int(c) for c in input_it.next().split())
        B = list(int(c) for c in input_it.next().split())
        y = case(A, N, B)
        print 'Case #{}: {}'.format(x, y)


if __name__ == '__main__':
    main()
