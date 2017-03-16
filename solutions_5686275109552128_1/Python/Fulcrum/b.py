def read_ints(file):
    line = file.readline().strip().split()
    return map(int, line)


def input():
    filename = __file__.split('.')[0] + '.in'
    with open(filename) as file:
        tests_count = int(file.readline().strip())

        for test_index in xrange(tests_count):
            file.readline()
            yield read_ints(file)


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


def solve(data):
    data.sort(reverse=True)
    minimum = data[0]

    for level in xrange(minimum - 1, 1, -1):
        operations = 0
        for plate in data:
            if plate <= level:
                break

            operations += (plate - 1) / level

        minimum = min(minimum, operations + level)

    return minimum


def main():
    results = output()
    results.next()

    for data in input():
        results.send(solve(data))

    results.close()


if __name__ == '__main__':
    main()
