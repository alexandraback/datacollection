



IMPOSSIBLE = 'INSOMNIA'


def find_last_count(n):
    if n <= 0:
        return IMPOSSIBLE
    else:
        current_count = 0
        appeared_digits = set()
        while len(appeared_digits) < 10:
            current_count += n
            rem = current_count
            while rem > 0:
                appeared_digits.add(rem % 10)
                rem //= 10
        return current_count


INPUT = 'A-small-attempt0.in'
OUTPUT = 'A-small-attempt0.out'


with open(INPUT, 'r') as fin:
    nb_cases = int(fin.readline())
    with open(OUTPUT, 'w') as fout:
        for i in xrange(1, nb_cases + 1):
            fout.write('Case #{}: {}\n'.format(i, find_last_count(int(fin.readline()))))