



IMPOSSIBLE = 'IMPOSSIBLE'


def tiles_to_clean_small(k, c, s):
    if k != s:
        raise Exception('k != s')
    return ' '.join(map(str, xrange(1, k + 1)))


INPUT = 'D-small-attempt0.in'
OUTPUT = 'D-small-attempt0.out'


with open(INPUT, 'r') as fin:
    nb_cases = int(fin.readline())
    with open(OUTPUT, 'w') as fout:
        for i in xrange(1, nb_cases + 1):
            k, c, s = map(int, fin.readline().split())
            fout.write('Case #{}: {}\n'.format(i, tiles_to_clean_small(k, c, s)))