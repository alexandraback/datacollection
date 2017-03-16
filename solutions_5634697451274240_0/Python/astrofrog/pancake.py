# Author: Thomas P. Robitaille
# Executed using Python 3

MAPPING = str.maketrans('+-', '-+')


def flip(pancakes, pos):
    """
    Flip a stack of pancakes at position (and including) ``pos``.
    """
    return pancakes[:pos + 1][::-1].translate(MAPPING) + pancakes[pos + 1:]


def find_optimal_flips(pancakes):
    """
    Given a stack of pancakes represented by + and -, with the top pancake at
    the start of the string, find the optimal number of flips to get them all
    to be '+'.
    """

    n = len(pancakes)

    n_flip = 0

    # We start from the last pancake and work our way to the top.
    for j in range(n - 1, - 1, -1):

        # Hard code the following two cases for efficiency
        if not '-' in pancakes:
            break  # all done!
        elif not '+' in pancakes:
            n_flip += 1
            break  # only one more flip

        # If the current pancake is + then we can just keep on going up
        if pancakes[j] == '+':
            continue
        else:
            if pancakes[0] == '-':
                # If the first pancake is -, then flipping from 0 to j will
                # result in that - becoming + at location j, which is good.
                pancakes = flip(pancakes, j)
                n_flip += 1
            else:
                # However, if the first pancake is also +, then we first need
                # to flip the first pancake. In fact, we should even flip
                # several if there are more than one consecutive + at the top.
                first = pancakes.index('-')
                pancakes = flip(pancakes, first - 1)
                pancakes = flip(pancakes, j)
                n_flip += 2

    return n_flip


with open('B-small-attempt0.in', 'r') as f:
    t = int(f.readline())
    for i in range(t):
        s = f.readline().strip()
        print("Case #{0}: {1}".format(i + 1, find_optimal_flips(s)))
