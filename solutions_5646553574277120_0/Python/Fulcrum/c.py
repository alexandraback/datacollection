from itertools import combinations


def read_ints(file):
    line = file.readline().strip().split()
    result = tuple(map(int, line))
    return result


def input():
    filename = __file__.split('.')[0] + '.in'
    with open(filename) as file:
        tests_count = int(file.readline().strip())

        for test_index in xrange(tests_count):
            c, d, v = read_ints(file)
            existing = read_ints(file)
            yield existing, c, v


def output():
    filename = __file__.split('.')[0] + '.out'
    with open(filename, 'w') as file:
        i = 0
        while True:
            value = (yield)
            if value is None:
                return

            i += 1
            file.write('Case #%d: %s\n' % (i, value))


def recursive_solve(existing_meta, c, v):
    if c:
        existing_meta.add(c)
    for coin in list(existing_meta):
        if coin + c <= v:
            existing_meta.add(coin + c)

    for i in xrange(1, v):
        if i not in existing_meta:
            min_missing = i
            break
    else:
        return 0

    candidates = [min_missing] + [min_missing - e for e in existing_meta if min_missing - e > c and min_missing - e not in existing_meta]
    #print existing_meta, min_missing, candidates

    answers = [recursive_solve(set(existing_meta), candidate, v) for candidate in candidates]

    return min(answers) + 1


def solve(existing, c, v):
    existing_meta = set()

    for length in xrange(1, len(existing) + 1):
        for combination in combinations(existing, length):
            existing_meta.add(sum(combination))

    for coin in list(existing_meta):
        for i in xrange(1, c + 1):
            existing_meta.add(coin * i)

    existing_meta = set(e for e in existing_meta if e <= v)

    return recursive_solve(existing_meta, 0, v)


def main():
    results = output()
    results.next()

    for data in input():
        results.send(solve(*data))

    results.close()


if __name__ == '__main__':
    main()
