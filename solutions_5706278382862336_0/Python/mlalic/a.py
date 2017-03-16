from fractions import Fraction


def is_power_of_2(num):
    return num != 0 and ((num & (num - 1)) == 0)

def calculate_purity(a, b):
    elfness = Fraction(a, b)
    if elfness.denominator % 2 == 1:
        return 'impossible'

    generations = 1
    half = Fraction(1, 2)

    while elfness < half:
        generations += 1
        if generations > 40:
            return 'impossible'
        elfness *= 2

    if not is_power_of_2(elfness.denominator):
        return 'impossible'

    return generations


def main():
    import sys
    T = int(sys.stdin.readline().strip())
    for test in xrange(T):
        a, b = map(int, sys.stdin.readline().strip().split('/'))

        print 'Case #{0}: {1}'.format(test + 1, calculate_purity(a, b))

if __name__ == '__main__':
    main()
