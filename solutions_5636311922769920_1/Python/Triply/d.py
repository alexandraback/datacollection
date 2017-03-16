



IMPOSSIBLE = 'IMPOSSIBLE'


def tiles_to_clean_small(k, c, s):
    if k != s:
        raise Exception('k != s')
    return ' '.join(map(str, xrange(1, k + 1)))


def choices_to_int(choices, base):
    result = 0
    for choice in choices:
        result = result * base + choice
    return result


def tiles_to_clean(k, c, s):
    min_students = (k + c - 1) // c
    if s < min_students:
        return IMPOSSIBLE
    else:
        result = []
        current = 0
        while current < k:
            start = current
            end = min(current + c, k)
            result.append(choices_to_int(xrange(start, end), k) + 1)
            current = end
        return ' '.join(map(str, result))


INPUT = 'D-large.in'
OUTPUT = 'D-large.out'


with open(INPUT, 'r') as fin:
    nb_cases = int(fin.readline())
    with open(OUTPUT, 'w') as fout:
        for i in xrange(1, nb_cases + 1):
            k, c, s = map(int, fin.readline().split())
            fout.write('Case #{}: {}\n'.format(i, tiles_to_clean(k, c, s)))
