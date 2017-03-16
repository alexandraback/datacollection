from fractions import Fraction


def solve():
    P, Q = raw_input().strip().split('/')
    a = Fraction(int(P), int(Q))
    b = Fraction(1)
    ance = Fraction(1, 2 ** 40)
    for i in xrange(41):
        # print i
        left = a - b
        if left < 0:
            b = b / 2
            continue
        div = left / ance
        # print div
        # print div.numerator
        # print div.denominator
        if div.denominator == 1:
            return i
        b = b / 2
    return 'impossible'


def main():
    T = input()
    for i in xrange(1, T + 1):
        num = solve()
        print 'Case #%d:' % i,
        print num


if __name__ == '__main__':
    main()
