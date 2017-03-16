__author__ = 'rycus'

# Problem C: Fashion Police

FILENAME = 'res/2016_r1c_c.small'
OUTPUT_FILE = '%s.out' % FILENAME


def solve(j, p, s, k):
    jp = {(j1, p1): 0 for j1 in xrange(1, j+1) for p1 in xrange(1, p+1)}
    js = {(j1, s1): 0 for j1 in xrange(1, j+1) for s1 in xrange(1, s+1)}
    ps = {(p1, s1): 0 for p1 in xrange(1, p+1) for s1 in xrange(1, s+1)}

    combos = []

    for ji in xrange(1, j+1):
        for pi in xrange(1, p+1):
            for si in xrange(1, s+1):

                if jp[(ji, pi)] >= k:
                    continue

                if js[(ji, si)] >= k:
                    continue

                if ps[(pi, si)] >= k:
                    continue

                jp[(ji, pi)] += 1
                js[(ji, si)] += 1
                ps[(pi, si)] += 1

                combos.append('%d %d %d' % (ji, pi, si))

    return '%d\n%s' % (len(combos), '\n'.join(combos))


if __name__ == '__main__':
    with open(FILENAME) as input_file:
        with open(OUTPUT_FILE, 'w') as output_file:
            num_cases = int(input_file.readline())
            print 'Solving %d test cases' % num_cases

            for case in xrange(1, num_cases + 1):
                J, P, S, K = map(int, input_file.readline().split())
                result = solve(J, P, S, K)

                print 'Case #%d: %s' % (case, result)
                print >> output_file, 'Case #%d: %s' % (case, result)
