from fractions import Fraction

half = Fraction(1, 2)

def solve_gen(fraction, gen):
    #print(gen)
    if gen > 40:
        return None
    if fraction in (half, 1):
        return gen
    if fraction >= half:
        if solve_gen((fraction - half) * 2, gen + 1) is not None:
            return gen
        else:
            return None
    else:
        return solve_gen(fraction * 2, gen + 1)


def solve(fraction):
    return solve_gen(fraction, 1)

def read_one():
    return Fraction(input())

def main():
    ncases = int(input())
    for i in range(1, ncases + 1):
        dist = solve(read_one())
        print('Case #{}: {}'.format(i, dist if dist is not None else 'Impossible'))


main()
