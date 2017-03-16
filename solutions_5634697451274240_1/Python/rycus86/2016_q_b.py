__author__ = 'rycus86'

# Problem B: Revenge of the Pancakes

FILENAME = 'res/2016_q_b.large'
OUTPUT_FILE = '%s.out' % FILENAME


def solve(x):
    flips = 0

    while not all(x):
        odd = find_first_odd(x)

        if odd is None:
            break

        x[:odd] = [not p for p in reversed(x[:odd])]
        flips += 1

    # if the stack is reversed, flip it
    if not x[0]:
        flips += 1

    return flips


def find_first_odd(x):
    first = x[0]

    for idx in xrange(1, len(x)):
        if x[idx] != first:
            return idx


if __name__ == '__main__':
    with open(FILENAME) as input_file:
        with open(OUTPUT_FILE, 'w') as output_file:
            num_cases = int(input_file.readline())
            print 'Solving %d test cases' % num_cases

            for case in xrange(1, num_cases + 1):
                X = [ch == '+' for ch in input_file.readline().strip()]
                result = solve(X)

                print 'Case #%d: %s' % (case, result)
                print >> output_file, 'Case #%d: %s' % (case, result)
