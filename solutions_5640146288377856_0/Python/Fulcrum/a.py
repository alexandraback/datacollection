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
            rows, columns, width = read_ints(file)
            yield rows, columns, width


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


def solve(rows, columns, width):
    answer = (rows - 1) * (columns / width) + (columns / width + width)

    if columns % width == 0:
        answer -= 1

    return answer


def main():
    results = output()
    results.next()

    for data in input():
        results.send(solve(*data))

    results.close()


if __name__ == '__main__':
    main()
