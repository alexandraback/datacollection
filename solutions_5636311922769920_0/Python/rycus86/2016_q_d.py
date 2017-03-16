__author__ = 'rycus86'

# Problem D: Fractiles

FILENAME = 'res/2016_q_d.small'
OUTPUT_FILE = '%s.out' % FILENAME


def solve(k, c, s):
    return ' '.join([str(num + 1) for num in xrange(k)])


if __name__ == '__main__':
    with open(FILENAME) as input_file:
        with open(OUTPUT_FILE, 'w') as output_file:
            num_cases = int(input_file.readline())
            print 'Solving %d test cases' % num_cases

            for case in xrange(1, num_cases + 1):
                S, K, C = map(int, input_file.readline().split())
                result = solve(S, K, C)

                print 'Case #%d: %s' % (case, result)
                print >> output_file, 'Case #%d: %s' % (case, result)
