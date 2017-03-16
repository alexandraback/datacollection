def read_ints(file):
    line = file.readline().strip().split()
    result = tuple(map(int, line))
    if len(result) == 1:
        result = result[0]
    return result


def input():
    filename = __file__.split('.')[0] + '.in'
    with open(filename) as file:
        tests_count = int(file.readline().strip())

        for test_index in xrange(tests_count):
            line = file.readline().strip().split()
            fingerprint = map(int, line[1])
            yield fingerprint


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


def solve(fingerprint):
    extra = 0
    current_standing = 0

    for shyness, count in enumerate(fingerprint):
        if shyness <= current_standing:
            current_standing += count
        else:
            extra += (shyness - current_standing)
            current_standing = shyness + count

    return extra


def main():
    results = output()
    results.next()

    for fingerprint in input():
        results.send(solve(fingerprint))

    results.close()


if __name__ == '__main__':
    main()
