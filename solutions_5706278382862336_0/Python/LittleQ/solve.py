import gcj, sys
from fractions import Fraction

squares = [ 2**x for x in range(1,41) ]


def guess_which_two(base):
    for a in squares:
        if base % a == 0:
            return [a]
        for b in squares:
            print a+b
            print 'mod:', (a+b) % base
            if base % (a * b) == 0:
                return [a, b]

    else:
        return None





def solve(up, down):
    if down not in squares:
        return 'impossible'

    for n, down2 in enumerate(squares):
        if Fraction(up, down) >= Fraction(1, down2):
            return n + 1


if __name__ == '__main__':
    IN = gcj.FileWrapper(open(sys.argv[1]))
    N = IN.getInt()

    for n in range(N):
        fraction = IN.getWords()[0]
        up, down = fraction.split('/')
        up, down = int(up), int(down)

        minimum_fraction = Fraction(up, down)
        
        gcj.printCase(solve(minimum_fraction.numerator, minimum_fraction.denominator))




        


