import sys
import fractions
import math

def min_generation(fraction, max_gen):

    ancestors = 2**max_gen
    elves = fraction * ancestors

    if elves.denominator != 1:
        return None

    generations_left = int(math.log(elves.numerator, 2))

    return max_gen - generations_left


if __name__ == "__main__":

    T = int(sys.stdin.readline())

    for case in range(1, T+1):

        fraction = fractions.Fraction(sys.stdin.readline().strip())

        solution = min_generation(fraction, 40)

        if solution is None:
            solution = "impossible"

        print("Case #{}: {}".format(case, solution))