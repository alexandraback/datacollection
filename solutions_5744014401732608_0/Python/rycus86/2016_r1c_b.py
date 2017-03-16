__author__ = 'rycus'

# Problem B: Slides!

FILENAME = 'res/2016_r1c_b.small'
OUTPUT_FILE = '%s.out' % FILENAME


class Matrix(object):

    def __init__(self, size):
        self.n = size
        self.data = [0] * (size ** 2)

    def get(self, start, end):
        return self.data[end + start * self.n]

    def set(self, start, end):
        self.data[end + start * self.n] = 1

    def __str__(self):
        lines = []

        for start in xrange(self.n):
            row = ''

            for end in xrange(self.n):
                row += str(self.get(start, end))

            lines.append(row)

        return '\n'.join(lines)


def solve(b, m):
    matrix = Matrix(b)
    paths = 0

    for combo in generate_combinations(b):

        for idx in xrange(len(combo) - 1):
            matrix.set(combo[idx], combo[idx+1])

        paths += 1

        if paths == m:
            break

    else:
        return 'IMPOSSIBLE'

    return '%s\n%s' % ('POSSIBLE', str(matrix))


def generate_combinations(b):
    yield (0, b-1)

    import itertools
    for r in xrange(b-1, 0, -1):
        for c in itertools.combinations(range(1, b-1), r):
            yield (0,) + c + (b-1,)


if __name__ == '__main__':
    with open(FILENAME) as input_file:
        with open(OUTPUT_FILE, 'w') as output_file:
            num_cases = int(input_file.readline())
            print 'Solving %d test cases' % num_cases

            for case in xrange(1, num_cases + 1):
                B, M = map(int, input_file.readline().split())
                result = solve(B, M)

                print 'Case #%d: %s' % (case, result)
                print >> output_file, 'Case #%d: %s' % (case, result)
