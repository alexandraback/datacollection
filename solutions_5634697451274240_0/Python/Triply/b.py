
import itertools


def min_flips(stack):
    result = sum(0 if a == b else 1 for (a, b) in itertools.izip(stack, stack[1:]))
    if stack[-1] == '-':
        result += 1
    return result


INPUT = 'B-small-attempt0.in'
OUTPUT = 'B-small-attempt0.out'

with open(INPUT, 'r') as fin:
    nb_cases = int(fin.readline())
    with open(OUTPUT, 'w') as fout:
        for i in xrange(1, nb_cases + 1):
            fout.write('Case #{}: {}\n'.format(i, min_flips(fin.readline().strip())))