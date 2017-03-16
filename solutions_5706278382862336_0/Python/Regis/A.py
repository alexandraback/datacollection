import sys
import fractions

powers = [2 ** x for x in range(1, 41)]


def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)


def solve(P, Q):
    div = P / Q
    if div > 0.5 and Q in powers:
        return 1

    rdiv = Q / P
    if int(rdiv) == rdiv and int(rdiv) in powers:
        return powers.index(rdiv) + 1

    if is_power2(int(Q)):
        for i in range(len(powers)):
            if P > powers[i]:
                return i

    return "impossible"

def solve2(P, Q):
    div = P / Q
    if div > 0.5 and Q in powers:
        return 1

    f = fractions.Fraction(int(P), int(Q))
    P = float(f.numerator)
    Q = float(f.denominator)

    rdiv = Q / P
    if int(rdiv) == rdiv and int(rdiv) in powers:
        return powers.index(rdiv) + 1

    if is_power2(int(Q)):
        for i in range(len(powers)):
            if float(powers[i]) / Q > float(P) / Q:
                rd = float(Q) / float(powers[i])
                return powers.index(rd) + 2

    return "impossible"


def main(filename):
    with open(filename, "r") as f:
        T = int(f.readline().strip())
        for t in xrange(T):
            l = f.readline().strip()
            P, Q = tuple([float(x) for x in l.split("/")])
            result = solve2(P, Q)
            print "Case #%d: %s" % (t+1, result)


if __name__ == "__main__":
    main(sys.argv[1])
