from sys import stdin
from fractions import Fraction


input_it = iter(stdin)

T = int(input_it.next())

for t in range(T):

    # interpret input
    # N: number of nodes
    # E: tuple of pairs of nodes
    P, Q = tuple(int(i) for i in input_it.next().split('/'))

    F = Fraction(P, Q)

    if (P * 2 ** 40 % Q) != 0:
        print 'Case #{x}: {y}'.format(x=t + 1, y='impossible')
        continue

    P2 = P * 2 ** 40 / Q  # P if Q were 2 ** 40

    y = 40
    while 1 < P2:
        y -= 1
        P2 >>= 1

    print 'Case #{x}: {y}'.format(x=t + 1, y=y)
